#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <sys/timeb.h>
#include <string.h>
#include <iostream>
#include <termios.h>//串口
using namespace std;
/*
    struct _timeb{
      time_t time;
      unsigned short millitm;
      short timezone, dstflag;
    };

      time是从UTC时间1970年1月1日午夜(00:00:00)起累计的秒数；
      millitm是一秒内的毫秒数
      dstflag不为0，说明这是夏令时时间
      timezone是UTC时间和本地时间的相差分钟数
	modify test
 */
long long getSystemTime()
{
    struct timeb t;
    ftime(&t);
    cout<< t.time << " " << t.millitm <<" " << 1000*t.time + t.millitm <<endl;
    return 1000*t.time + t.millitm;
}

long long start;
long long end;

pthread_mutex_t mutex;
int fd_gpio;

struct termios newtio,oldtio;

typedef struct
{
    int pin_idx;
    int pin_dir;
    int pin_sta;
}davinci_gio_arg;

typedef enum
{
    AT91PIO_DIR_OUT = 0,
    AT91PIO_DIR_INP
}davinci_gio_dir;

#define DEV_PIO_LED "/dev/pio"

#define PIO_NUM 47
#define DEV_UART "/dev/ttyS1"


#define IOCTL_PIO_SETDIR    1       //set gpio direct
#define IOCTL_PIO_GETDIR    2       //get gpio direct
#define IOCTL_PIO_SETSTA    3       //set gpio status
#define IOCTL_PIO_GETSTA    4       //get gpio status


int log_init(const char *strFileName)
{
    int fdLog = -1;
    if(-1 == (fdLog = open(strFileName,O_CREAT|O_TRUNC)))
    {

    }
    close(fdLog);
}

int log_out(const char *strFileName,const char *szLog)
{
    int fdLog = -1;
    if(-1 == (fdLog = open(strFileName,O_CREAT | O_WRONLY | O_APPEND)))
    {
        printf("Log (%s) open error !\n",strFileName);
        return -1;
    }

    write(fdLog,szLog,strlen(szLog));
    close(fdLog);
    return 0;
}

int set_com_opt(int fd,int nspeed,int nbits ,char parity,int nstop)
{
    char szTmp[128];
    sprintf(szTmp,"set_com_opt - speed:%d ,bits %d, parity:%c, stop:%d\n ",nspeed,nbits,parity,nstop);
    log_out("./485.log",szTmp);

    if(tcgetattr(fd,&oldtio) != 0)
    {
        sprintf();
        log_out();
        perror("SetupSerial 1");
        return -1;
    }

    bzero(&newtio,sizeof(newtio));
    newtio.c_cflag  &=~(OPOST);

    newtio.c_cflag |= (LOCAL | CREAD);
    newtio.c_cflag &= ~CSIZE;

    switch(nbits)
    {
    case 7:
        newtio.c_cflag |= CS7;
        break;
    case 8:
        newtio.c_cflag |= CS8;
        break;
    default:
        perror();
        return -1;
    }


    swich(parity)
    {
        case 'n':
        case 'N':
            newtio.c_cflag &= ~PARENB;
            newtio.c_iflag &= ~INPCK;
            break;
        case 'o':
        case 'O':
            newtio.c_cflag |= ( PARODD | PARENB );
            newtio.c_iflag |= ( INPCK | ISTRIP );
            break;
        case 'e':
        case 'E':
            newtio.c_iflag |= ( INPCK |ISTRIP );
            newtio.c_cflag |= PARENB;
            newtio.c_cflag &= ~PARODD;
            break;

        default:
            perror();
            return -1;
    }

    swich(nstop)
    {

        case 1:
            newtio.c_cflag &= ~CSTOPB;
        case 2:
            newtio.c_cflag |= CSTOPB;
        default:
            perro();
            return -1;
    }

    switch( nspeed )
    {
    case 2400:
        cfsetispeed( &newtio, B2400 );
        cfsetospeed( &newtio, B2400 );
        break;
    case 4800:
        cfsetispeed( &newtio, B4800 );
        cfsetospeed( &newtio, B4800 );
        break;
    case 9600:
        cfsetispeed( &newtio, B9600 );
        cfsetospeed( &newtio, B9600 );
        break;
    case 115200:
        cfsetispeed( &newtio, B115200 );
        cfsetospeed( &newtio, B115200 );
        break;
    case 460800:
        cfsetispeed( &newtio, B460800 );
        cfsetospeed( &newtio, B460800 );
        break;
    default:
        cfsetispeed( &newtio, B9600 );
        cfsetospeed( &newtio, B9600 );
        break;
    }


    //设置等待时间和最小接收字符
    newtio.c_cc[VTIME] = 0;
    newtio.c_cc[VMIN] = 0;

    //VTIME=0，VMIN=0，不管能否读取到数据，read都会立即返回。


    //输入模式
    newtio.c_lflag &= ~(ICANON|ECHO|ECHOE|ISIG);
    //设置数据流控制
    newtio.c_iflag &= ~(IXON|IXOFF|IXANY); //使用软件流控制
    //如果发生数据溢出，接收数据，但是不再读取 刷新收到的数据但是不读
    tcflush( fd, TCIFLUSH );
    //激活配置 (将修改后的termios数据设置到串口中）
    if( tcsetattr( fd, TCSANOW, &newtio ) != 0 )
    {
        sprintf( szTmp, "serial set error!\n" );

        log_out( "./485.log", szTmp );
        perror( "serial set error!" );
        return -1;
    }

    log_out( "./485.log", "serial set ok!\n" );
    return 1;
}



int open_com_dev(char *dev_name)
{
    int fd;
    char sztmp[128];
    log_init("./485.log");
    if((fd = open(dev_name,O_RDWR | O_NOCTTY | O_NDELAY)) == -1)
    {
        perror();
        sprintf();
        log_out();
        return -1;
    }

    sprintf(sztmp,"open %s ok!\n",dev_name);
    log_out("./485.log",sztmp);

    if(fcntl(F_SETFL,0) < 0)
    {
        printf();

    }

    return fd;

}

int main(int argc,char *argv[])
{
    long long v_time = getSystemTime();
    cout<< "time = " <<v_time <<endl;

    return 0;
}



