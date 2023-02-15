#include <stdio.h>    //输入输出函数
#include <stdlib.h>    //定义杂项函数及内存分配函数
#include <windows.h>   //写window程序需要的重要头文件。
#include <ctype.h>      //字符处理 
#include <string.h>      //字符串处理
#include <time.h>      //定义关于时间的函数  
#include <math.h>      //定义数学函数
#include <float.h>     //浮点数处理  

//函数结果状态
#define TRUE    1
#define FALSE   0
#define OK      1
#define ERROR   0
#define OVERFLOW  -2
#define Status int
#define ElemType char

//--------线性表的动态分配顺序存储结构--------
#define LIST_INIT_SIZE    100  //线性表存储空间的初始分配量
#define LISTINCREMENT   10 //线性表存储空间的分配增量

//定义顺序表
typedef  struct LNode{      //定义顺序表存储结构
   ElemType  *elem;  //存储空间基址,动态数组起始地址
   int  listsize; //顺序表当前分配的存储容量(以sizeof(ElemType)为单位
   int  length;    //顺序表的当前长度,即表中数据元素的个数
}SqList;

//顺序表的初始化
Status InitList(SqList &L)
{
    L.elem=(ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    if(!L.elem)
    {
        return ERROR;
    }
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}

//判断顺序表是否为空
bool ListEmpty(SqList L)
{
    if(L.length==0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//计算顺序表的表长
int ListLength(SqList L)
{
    return L.length;
}

//打印顺序表的元素
void PrintList(SqList L)
{
    for(int i=0;i<L.length;i++)
    {
        printf("%c ",L.elem[i]);
    }
}
//在顺序表中插入元素
Status ListInsert(SqList &L,int i,ElemType e)
{
    if(i<0 || i>L.length+1)
    {
        return ERROR;
    }
    if(L.length>L.listsize)
    {
        ElemType *newbase;
        newbase=(ElemType *)realloc(L.elem,sizeof(ElemType)*(L.listsize+LISTINCREMENT));
        L.elem=newbase;
        L.listsize=L.listsize+LISTINCREMENT;
    }
    for(int k=L.length;k>=i;k--)
    {
        L.elem[k]=L.elem[k-1];
    }
    L.elem[i-1]=e;
    L.length++;
    return OK;
}
//查找顺序表的第i个元素
Status GetElem(SqList &L, int i, ElemType &e)
{
    if(L.length==0 || i<0 || i>L.length)
    {
        return ERROR;
    }
    e=L.elem[i-1];
    return e;
}
//在顺序表中查找元素e
Status LocateElem(SqList &L, ElemType e)
{
    if(L.length==0)
    {
        return ERROR;
    }
    for(int i=0;i<L.length;i++)
    {
        if(L.elem[i]==e)
        {
            return i+1;
        }
    }
    return ERROR;
}
//顺序表中删去第i个元素
Status ListDelete(SqList &L, int i, ElemType &e)
{
   if(L.length==0 || i<0 || i>L.length)
    {
        return ERROR;
    }
    for(int k=i;k<L.length;k++)
    {
        L.elem[k-1]=L.elem[k];
    }
    L.length--;
    return OK;
}
//合并两个顺序表
void MergeList(SqList &La, SqList &Lb, SqList &Lc)
{
    int i=0,j=0,k=0;
    Lc.listsize=Lc.length=La.length+Lb.length;
    Lc.elem=(ElemType *)malloc(sizeof(ElemType)*Lc.listsize);
    while(i<La.length && j<Lb.length)
    {
        if(La.elem[i]<=Lb.elem[j])
        {
            Lc.elem[k]=La.elem[i];
            i++;
        }
        else
        {
            Lc.elem[k]=Lb.elem[j];
            j++;
        }
        k++;
    }
    while(i<La.length)
    {
        Lc.elem[k]=La.elem[i];
        i++;
        k++;
    }
    while(j<Lb.length)
    {
        Lc.elem[k]=Lb.elem[j];
        j++;
        k++;
    }
}



