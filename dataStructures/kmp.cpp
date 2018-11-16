#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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
            next[i] = j;//存储相同字符的长度
        }
        else
        {
            j = next[j];
        }
    }



}

/*
 * KMP算法过程
 * 假设现在的文本串S匹配到i的位置，模式串P匹配到j的位置，则有：
 * --如果当前字符匹配成功(S[i]==P[j]),则i++，j++，继续匹配下一个字符；
 * --如果失配，(即S[i]!=P[j]),令i=i-(j-1),j=0。相当于每次匹配失败时，j回溯到next[j]
 * j当前模式串P的位置，j-1即当前位置-1回到上一个字符相同的位置，i-(j-1),减去上一次匹配相同字符串的长度，即为i回溯的位置。j则回溯到0的位置。
 *
 *
 * 可以发现：KMP算法和暴力匹配算法（BF算法）区别在于KMP算法中i不需要回溯  且j回溯到next[j]的位置。
 *
 *
 * j每次回溯的移动位数就是已经匹配的字符数-对应匹配值
 */


void getNext(string p,int next[])
{
    //int len = p.length();
    int len = p.size();
    //cout << "len = " << len << ",len2 = "<<len2 << endl;
    int i = 0;
    int j = -1;
    next[0] = -1;

    while(i < len-1)//i < len - 1?
    {
        cout << p[i] << "--" << p[j] << endl;
        if(j == -1 || p[i] == p[j])
        {
            i++;
            j++;
            next[i] = j;
            cout <<"--" <<"i = " << i << ",next[i]=" <<  next[i] << endl;
        }
        else
        {
            j = next[j];
            cout << "**" << next[i] << endl;
        }
    }

}

int KMP(string S, string P, int next[])
{
    getNext(P, next);

    for(int m = 0; m < P.size()+1; m++)
    {
        cout << m << "-"<< next[m] << endl;
    }

    int i = 0;  // S 的下标
    int j = 0;  // P 的下标
    int s_len = S.size();
    int p_len = P.size();

    while (i < s_len && j < p_len)
    {
        if (j == -1 || S[i] == P[j])  // P 的第一个字符不匹配或 S[i] == P[j]
        {
            i++;
            j++;
        }
        else
            j = next[j];  // 当前字符匹配失败，进行跳转
    }

    if (j == p_len)  // 匹配成功
        return i - j;

    return -1;
}

int main(int argc,char *argv[])
{
    //int p = bf((char*)"abdeabcdefg",(char*)"abcd");



    string str = "bbc abcdab abcdabcdabde";
    string sub_str = "abcdabd";
    int sub_str_len = sub_str.size();
    int next[sub_str_len] ;
    int post = KMP(str,sub_str,next);
    cout << post << endl;
//    int i = 0;
//    while(next[i] != '\0')
//    {
//        cout << next[i] << endl;
//        i++;
//    }



    return 0;
}
