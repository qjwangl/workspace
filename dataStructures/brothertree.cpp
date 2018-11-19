#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#define M 100

typedef struct{//定义数组元素结构
    char data;//
    int child,nextsib;//指针式整数型
}CSNODE;

typedef struct{ //定义兄弟列表
    CSNODE element[M];//
    int n;//实际元素个数
}BNODE;

