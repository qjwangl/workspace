#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "hello.h"
using namespace std;

void print_usage(void)
{
    fprintf(stderr, "Usage: lsgpio [options]...\n"
        "List GPIO chips, lines and states\n"
        "  -n <name>  List GPIOs on a named device\n"
        "  -?         This helptext\n"
    );
}

int main(int argc, char *argv[])
{
    //cout << "Hello World!" << endl;
    hellotest();
    char *device_name = NULL;
    char *device_num = NULL;
    int c;

    while ((c = getopt(argc, argv, "n:c:")) != -1)
    {
        switch (c) {
        case 'n':
            device_name = optarg;
            break;
        case 'c':
            printf("HAVE option: -c\n");
            printf("The argument of -c is %s\n\n", optarg);
            device_num = optarg;
            break;
        case '?':
            print_usage();
            break;
        default:
            printf("------------ \n");
            break;
        }
    }
    cout<<"device_name = "<< device_name <<",device_num = "<< device_num <<endl;
    return 0;
}
