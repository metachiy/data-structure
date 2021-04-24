/*
读数据O(1)，增删数据O(n)

优势：
-无需为表示表中元素之间的逻辑关系而增加额外的存储空间
-可以快速存取表中任意位置的元素

缺点：
-插入和删除操作需要移动大量元素
-当线性表长度变化较大时，难以确定存储空间的容量
-容易造成存储空间的 “碎片”
*/
#include <stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;

Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i - 1];
    return OK;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
    if (L->length == MAXSIZE)
        return ERROR;
    if (i < 1 || i > L->length + 1)
        return ERROR;
    //若插入数据不在表尾
    if (i <= L->length)
    {
        //将插入位后从末位开始依次后移一位
        for (int k = L->length - 1; k >= i - 1; k--)
            L->data[k + 1] = L->data[k];
    }
    L->data[i - 1] = e;
    L->length ++;

    return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e)
{
    if (L->length == 0)
        return ERROR;
    if (i < 1 || i > L->length)
        return ERROR;
    *e = L->data[i - 1];
    if (i < L->length)
    {
        for (int k = i; k < L->length; k++)
            L->data[k - 1] = L->data[k];
    }    
    L->length --;

    return OK;
}

