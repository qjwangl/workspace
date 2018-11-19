#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define MAX_TREE_SIZE 100

typedef char TelemType;

typedef struct FLNode
{
    TelemType data;//节点数据
    int father;//双亲位置
}FLNode;

typedef struct FTree
{
    FLNode element[MAX_TREE_SIZE];//节点数组
    int r,n;//根的位置和节点数
}FTree;

FTree createParentTree()
{
    FTree tree;
    tree.n = 10;

    FLNode node;

    //A
    node.data = 'A';
    node.father = -1;
    tree.element[0] = node;

    //B
    node.data = 'B';
    node.father = 0;
    tree.element[1] = node;

    //C
    node.data = 'C';
    node.father = 0;
    tree.element[2] = node;


    //D
    node.data = 'D';
    node.father = 0;
    tree.element[3] = node;

    //E
    node.data = 'E';
    node.father = 1;
    tree.element[4] = node;

    //F
    node.data = 'F';
    node.father = 1;
    tree.element[5] = node;

    //H
    node.data = 'H';
    node.father = 3;
    tree.element[6] = node;

    //I
    node.data = 'I';
    node.father = 3;
    tree.element[7] = node;

    //G
    node.data = 'G';
    node.father = 6;
    tree.element[8] = node;

    //K
    node.data = 'K';
    node.father = 7;
    tree.element[9] = node;

    return tree;
}

void printFatherTree(FTree tree)
{
    printf("\n");
    printf("tree={");
    printf("{");
    int flag = 0;
    for(int i = 0; i < tree.n && i < MAX_TREE_SIZE; i++ )
    {
        if(flag == 0)
        {
            cout << tree.element[i].data;
            flag = 1;
        }
        else
        {
            cout << tree.element[i].data;
        }

    }

    printf("}");
    printf("%d",tree.n);
    printf("}\n");
    printf("\n");
}


void printFLNode(int position, FLNode node)
{
    printf("(位置号:%d,数据域:%c,父节点:%d)\n",position,node.data,node.father);
}

void getFatherTreeRoot(FTree tree)
{
    printf("\n");
    //遍历数组，找到指针域为-1的节点，就是根节点
    for(int i = 0; i< tree.n;i++)
    {
        FLNode node = tree.element[i];
        if(node.father == -1)
        {
            printf("tree的根节点--->");
            printFLNode(i,node);
            break;
        }
    }
    printf("\n");
}

void getFatherTreeNodeChilds(FTree tree,int position)
{
    printf("\n");
    //1判断数组总是否存在在此位置的元素是不是
    if(tree.n == 0 || position >= tree.n)
    {
        printf("树中不存在位置号为%d的节点\n",position);
        return ;
    }

    FLNode node = tree.element[position];
    for(int i = 0; i < tree.n;i++)
    {
        if(tree.element[i].father == position)
        {
            printFLNode(i,tree.element[i]);
        }
    }
}

int main(int argc,char *argv[])
{
    FTree tree = createParentTree();
    printFatherTree(tree);

    getFatherTreeRoot(tree);

    getFatherTreeNodeChilds(tree,3);

    return 0;
}






































