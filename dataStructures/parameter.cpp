#include <iostream>
#include <stdlib.h>
using namespace std;
struct ListNode
{
    int value;
    struct ListNode *next;
};

typedef struct Stack
{
    int stack_value;
    struct ListNode *stop;
}STACK;


void InitList1(ListNode **pHead)
{
    *pHead = new ListNode;
    if(*pHead != NULL)
    {
        (*pHead)->value = 1;
        (*pHead)->next = NULL;
    }
    cout << "InitList1 Success !" << endl;
}


void InitList2(ListNode *&pHead)
{
    pHead = new ListNode;
    if(pHead != NULL)
    {
        pHead->value = 2;
        pHead->next = NULL;
    }
    cout << "InitList2 Success !" << endl;
}


void InitList3(STACK *sc)
{
    ListNode *pHead = new ListNode;
    pHead->value = 3;
    pHead->next = NULL;
    sc->stop = pHead;
    sc->stack_value = 31;
    cout << "InitList3 Success !" << pHead->value <<endl;
}

void InitList4(ListNode *pHead)
{
    //pHead = new ListNode;
    cout << (void*)pHead << endl; //地址发生了变化
    pHead->value = 4;
    pHead->next = NULL;
    cout << "InitList4 Success !" << pHead->value <<endl;
}

void DisplayList(ListNode *pHead)
{
    ListNode *list = pHead;
    while(list != NULL)
    {
        cout << list->value << endl;
        list = list->next;
    }
}

int main(int argc,char *argv[])
{
    ListNode *head1;
    InitList1(&head1);
    DisplayList(head1);

    ListNode *head2;
    InitList2(head2);
    DisplayList(head2);

    STACK sc;
    cout << &sc << endl;
    InitList3(&sc);
    cout << &sc << endl;
    cout << sc.stop->value << endl;
    cout << sc.stack_value << endl;

    //失败,值未能传出来，3和4有什么区别?
    cout << "---------------------------" << endl;
    ListNode head4;
    cout << &head4 << endl;
    InitList4(&head4);
    cout << &head4 << endl;
    cout << head4.value << endl;

    return 0;
}


/*输出结果
 *
InitList1 Success !
1
InitList2 Success !
2
InitList3 Success !3
3
31
InitList4 Success !4
-1444608160
*/
