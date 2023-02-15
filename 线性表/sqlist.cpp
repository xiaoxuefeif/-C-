#include <stdio.h>    //�����������
#include <stdlib.h>    //������������ڴ���亯��
#include <windows.h>   //дwindow������Ҫ����Ҫͷ�ļ���
#include <ctype.h>      //�ַ����� 
#include <string.h>      //�ַ�������
#include <time.h>      //�������ʱ��ĺ���  
#include <math.h>      //������ѧ����
#include <float.h>     //����������  

//�������״̬
#define TRUE    1
#define FALSE   0
#define OK      1
#define ERROR   0
#define OVERFLOW  -2
#define Status int
#define ElemType char

//--------���Ա�Ķ�̬����˳��洢�ṹ--------
#define LIST_INIT_SIZE    100  //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT   10 //���Ա�洢�ռ�ķ�������

//����˳���
typedef  struct LNode{      //����˳���洢�ṹ
   ElemType  *elem;  //�洢�ռ��ַ,��̬������ʼ��ַ
   int  listsize; //˳���ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ
   int  length;    //˳���ĵ�ǰ����,����������Ԫ�صĸ���
}SqList;

//˳���ĳ�ʼ��
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

//�ж�˳����Ƿ�Ϊ��
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

//����˳���ı�
int ListLength(SqList L)
{
    return L.length;
}

//��ӡ˳����Ԫ��
void PrintList(SqList L)
{
    for(int i=0;i<L.length;i++)
    {
        printf("%c ",L.elem[i]);
    }
}
//��˳����в���Ԫ��
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
//����˳���ĵ�i��Ԫ��
Status GetElem(SqList &L, int i, ElemType &e)
{
    if(L.length==0 || i<0 || i>L.length)
    {
        return ERROR;
    }
    e=L.elem[i-1];
    return e;
}
//��˳����в���Ԫ��e
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
//˳�����ɾȥ��i��Ԫ��
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
//�ϲ�����˳���
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



