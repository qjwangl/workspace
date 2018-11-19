#include <stdio.h>
#include <iostream>

using namespace std;

#define M 100

typedef struct cnode//定义链结点
{
    int cno;//子结点号
    struct cnode *next;//下一结点指针
}CLINK;

typedef struct{
    char data;//树结点信息域
    CLINK *header;//链头指针
}CTNODE;

typedef struct{//定义子链表
    CTNODE node[M];//头结点数组
    int n,root;//树的结点个数,根结点位置号
}CLTREE;


