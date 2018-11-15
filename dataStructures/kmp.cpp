#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;


int bf(char *ts, char *ps)
{
    int i = 0;//
    int j = 0;
    char t[100];
    char p[100];
    strcpy(t,ts);
    strcpy(p,ps);

    int t_length = strlen(t);
    int p_length = strlen(p);

    while(i < t_length && j < p_length)
    {
        if(t[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j +1;
            j = 0;
        }
    }

    if(j == p_length)
    {
        return i-j;
    }
    else
    {
        return -1;
    }
}



void get_next(string str, int *next)
{
    int i = 1;
    int j = 0;
    next[1] = 0;
    while(i < str.length())
    {
        if(j == 0 || str[i] == str[j])//str[i] 后缀,str[i] 前缀
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }


}

int main(int argc,char *argv[])
{
    int p = bf((char*)"abdeabcdefg",(char*)"abcd");

    //cout << p << endl;

    string ps = "abcda";
    int next[10];
    get_next(ps,next);


    int i = 0;
    while(next[i] != '\0')
    {
        cout << next[i] << endl;
        i++;
    }

    return 0;
}
