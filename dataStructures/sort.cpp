#include <iostream>

using namespace std;

void array_test(int a[], int n)
{
    //int n = sizeof(a)/sizeof(int);//sizoef(a)的结果是指针变量a占内存的大小
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return ;
}

/*
 *冒泡排序为交换排序，每完成一轮交换，后位排序，先在为排序的序列中找到到最大的进行排序
 *冒泡排序时间复杂度为O(n^2),
 */
void bubbleSort(int a[],int n)
{
    if(n <= 1)
    {
        return ;
    }
    for(int i = 0; i < n; i++)
    {
        bool flag = false;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j+1])
            {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                flag = true;
            }
        }
        if(!flag)
        {
            break;
        }
    }

    return;
}

/*
 * 插入排序对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
 * 时间复杂度为O(n^2)
 */

void insertionSort(int a[], int n)
{
    if( n <=1 )
    {
        return ;
    }
    for(int i = 1; i < n ; i++)
    {
        int value = a[i];
        int j = i - 1;
        //查找插入的位置
        for(;j >= 0; j--)
        {
            if(a[j] > value)//如果该元素（已排序）大于新元素，将该元素移到下一位置；
            {
                a[j+1] = a[j];//移动数据
            }
            else
            {
                break;
            }
            cout << "for" << j << endl;
        }
        cout << j << endl;
        a[j+1] = value;//插入数据,j--做了-1的操作

    }

    return ;
}

/*
 * 从未排序的序列中找到最小的，进行交换
 * 时间复杂度为O(n^2)
 */
void selectionSort(int a[], int n)
{
    if(n <= 1)
    {
        return ;
    }
    int minIndex = 0;
    int tmp = 0;
    for(int i = 0; i < n - 1; i++)//执行n-1次，
    {
        minIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        tmp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = tmp;

    }
    return ;
}



void mergeSort_c(int a[], int begin, int end)
{
    if(begin >= end)
    {
        return ;
    }

    int middle = ( begin + end ) / 2;
    mergeSort_c(a, begin, middle);
    mergeSort_c(a, middle + 1, end);
}

void mergeSort(int a[], int n)
{
    mergeSort_c(a, 0, n - 1);
}



int main(int argc, char *argv[])
{
    int a[] = {1,3,5,2,4,6};

    int n = sizeof(a)/sizeof(int);
    //bubbleSort(a, n);
    //insertionSort(a, n);
    //selectionSort(a, n);
    mergeSort(a,n);
    //array_test(a, n);
    return 0;
}
