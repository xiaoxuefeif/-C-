#include <stdio.h>    //输入输出函数
#include <stdlib.h>    //定义杂项函数及内存分配函数
#include <windows.h>   //写window程序需要的重要头文件。
#include <ctype.h>      //字符处理 
#include <string.h>      //字符串处理
#include <time.h>      //定义关于时间的函数  
#include <math.h>      //定义数学函数
#include <float.h>     //浮点数处理  
#include"sqlist.cpp"

int main()
{
    SqList La,Lb,Lc;
    char e;
    //1.初始化顺序表La，Lb
    InitList(La);
    InitList(Lb);
    //2.在顺序表La中插入元素a,c,d,e,i
    ListInsert(La,1,'a');
    ListInsert(La,2,'c');
    ListInsert(La,3,'d');
    ListInsert(La,4,'e');
    ListInsert(La,5,'i');
    //3.输出顺序表
    printf("输出顺序表：\n");
    PrintList(La);
    printf("\n");
    //4.输出顺序表的长度
    printf("顺序表的长度为：\n%d",ListLength(La));
    //5.输出顺序表La是否为空
    printf("\n判断顺序表是否为空(空为1,非空为0)：\n%d\n",ListEmpty(La));
    //6.输出顺序表的第三个元素
    printf("顺序表的第三个元素为：\n%c\n",GetElem(La,3,e));
    //7.输出元素d的位置
    printf("元素d的位置为：\n%d\n",LocateElem(La,'d'));
    //8.在第5个元素的位置上插入元素f
    ListInsert(La,5,'f');
    //9.输出顺序表
    printf("输出顺序表：\n");
    PrintList(La);
    printf("\n");
    //10.删除顺序表La的第3个元素
    ListDelete(La,3,e);
    //11.输出顺序表
    printf("输出顺序表：\n");
    PrintList(La);
    printf("\n");
    //12.在顺序表Lb中插入元素a,b,d,g,h,j,k,l
    ListInsert(Lb,1,'a');
    ListInsert(Lb,2,'b');
    ListInsert(Lb,3,'d');
    ListInsert(Lb,4,'g');
    ListInsert(Lb,5,'h');
    ListInsert(Lb,6,'j');
    ListInsert(Lb,7,'k');
    ListInsert(Lb,8,'l');
    //13.合并顺序表La与Lb
    MergeList(La,Lb,Lc);
    //14.输出顺序表
    printf("输出合并后的顺序表：\n");
    PrintList(Lc);
    printf("\n");
    
    system("pause");

}