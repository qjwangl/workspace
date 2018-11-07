#include <iostream>
#include <sys/socket.h>
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    int sockfd,n;
    char recvline[MAXLINE+1];
    struct sockaddr_in servaddr;

    if(argc != 2)
    {
        //err_quit();
        printf("usage:\n");
    }
    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
    {

    }
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;

    return 0;
}
