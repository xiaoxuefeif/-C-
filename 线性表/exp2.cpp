#include <stdio.h>    //�����������
#include <stdlib.h>    //������������ڴ���亯��
#include <windows.h>   //дwindow������Ҫ����Ҫͷ�ļ���
#include <ctype.h>      //�ַ����� 
#include <string.h>      //�ַ�������
#include <time.h>      //�������ʱ��ĺ���  
#include <math.h>      //������ѧ����
#include <float.h>     //����������  
#include"sqlist.cpp"

int main()
{
    SqList La,Lb,Lc;
    char e;
    //1.��ʼ��˳���La��Lb
    InitList(La);
    InitList(Lb);
    //2.��˳���La�в���Ԫ��a,c,d,e,i
    ListInsert(La,1,'a');
    ListInsert(La,2,'c');
    ListInsert(La,3,'d');
    ListInsert(La,4,'e');
    ListInsert(La,5,'i');
    //3.���˳���
    printf("���˳���\n");
    PrintList(La);
    printf("\n");
    //4.���˳���ĳ���
    printf("˳���ĳ���Ϊ��\n%d",ListLength(La));
    //5.���˳���La�Ƿ�Ϊ��
    printf("\n�ж�˳����Ƿ�Ϊ��(��Ϊ1,�ǿ�Ϊ0)��\n%d\n",ListEmpty(La));
    //6.���˳���ĵ�����Ԫ��
    printf("˳���ĵ�����Ԫ��Ϊ��\n%c\n",GetElem(La,3,e));
    //7.���Ԫ��d��λ��
    printf("Ԫ��d��λ��Ϊ��\n%d\n",LocateElem(La,'d'));
    //8.�ڵ�5��Ԫ�ص�λ���ϲ���Ԫ��f
    ListInsert(La,5,'f');
    //9.���˳���
    printf("���˳���\n");
    PrintList(La);
    printf("\n");
    //10.ɾ��˳���La�ĵ�3��Ԫ��
    ListDelete(La,3,e);
    //11.���˳���
    printf("���˳���\n");
    PrintList(La);
    printf("\n");
    //12.��˳���Lb�в���Ԫ��a,b,d,g,h,j,k,l
    ListInsert(Lb,1,'a');
    ListInsert(Lb,2,'b');
    ListInsert(Lb,3,'d');
    ListInsert(Lb,4,'g');
    ListInsert(Lb,5,'h');
    ListInsert(Lb,6,'j');
    ListInsert(Lb,7,'k');
    ListInsert(Lb,8,'l');
    //13.�ϲ�˳���La��Lb
    MergeList(La,Lb,Lc);
    //14.���˳���
    printf("����ϲ����˳���\n");
    PrintList(Lc);
    printf("\n");
    
    system("pause");

}