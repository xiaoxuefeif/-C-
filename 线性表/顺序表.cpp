# include<stdio.h> 
# include<stdlib.h>
# include<string.h>
# include<math.h>
# include<stdbool.h>
# include<assert.h>
# include<ctype.h>

typedef int SLDataType;

// 动态顺序表
typedef struct SeqList
{
	SLDataType* a;
	int size;      // 有效数据个数 
	int capacity;  // 容量空间大小	
}SL;

// 接口函数
// 1.初始化函数 
void SeqListInit(SL*ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;	
} 

// 扩容函数 
void SeqListCheckCapacity(SL* ps)
{
	if(ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2; 
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*newcapacity);
		if(tmp == NULL)
		{
			printf("扩容失败\n");
			exit(-1); 
		}
		
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

// 2.向末尾插入元素 
void SeqListPushBack(SL* ps, SLDataType x)
{
	
	SeqListCheckCapacity(ps); 
	
	ps->a[ps->size] = x;
	ps->size++;
	
}

// 3.向开头插入元素 
void SeqListPushFront(SL* ps, SLDataType x)
{
	
	SeqListCheckCapacity(ps);
	
	// 挪动数据 
	int end = ps->size-1;
	while(end>=0)
	{
		ps->a[end+1] = ps->a[end];
		end--;	
	} 
	ps->a[0] = x;
	ps->size++;
}

// 4.删除末尾元素 
void SeqListPopback(SL* ps)
{
	
//	if(ps->size > 0)
//	{
//		ps->size--;
//	} 
	
	assert(ps->size > 0);
	ps->size--;
	
}

// 4.删除开头元素 
void SeqListPopFront(SL* ps)
{
	int begin = 0;
	while(begin<ps->size)
	{
		ps->a[begin] = ps->a[begin+1];
		begin++; 
	}
	ps->size--;
	
}

// 5.查找元素，返回顺序表所在位置 
int SeqListFind(SL* ps, SLDataType x)
{
	for(int i=0;i<ps->size;i++)
	{
		if(ps->a[i] == x)
		{
			return i+1;
		}
	}
	return -1; 
}

// 6.在指定位置插入
int SeqListInsert(SL* ps, int pos, SLDataType x)
{
	if(pos <= 0) printf("插入位置必须大于0");
	SeqListCheckCapacity(ps);
	
	int end = ps->size - 1;
	while(end >= pos-1)
	{
		ps->a[end+1] = ps->a[end];
		end--;	
	} 
	ps->a[pos-1] = x;
	ps->size++;
	return 1;
	 	
} 

// 7.在指定位置删除 
int SeqListErase(SL* ps, int pos, SLDataType x)
{
	if(pos <= 0) printf("删除位置必须大于0");
	
	int begin = pos;
	while(begin < ps->size)
	{
		ps->a[begin-1] = ps->a[begin];
		begin++;	
	} 
	ps->size--;
	return 1;
		
} 

// 打印 
void SeqListPrint(SL* ps)
{
	for(int i=0;i<ps->size;i++)
	{
		printf("%d ",ps->a[i]);
	}
	printf("\n"); 
} 




int main()
{
	SL sl;
	SeqListInit(&sl);
	printf("向末尾插入1，3，5，7，9\n"); 
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 9);	
	printf("打印数组\n"); 
	SeqListPrint(&sl);
	
	printf("向开头插入2，4，6，8，10\n"); 
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 6);
	SeqListPushFront(&sl, 8);
	SeqListPushFront(&sl, 10);	
	printf("打印数组\n"); 
	SeqListPrint(&sl);
	
	printf("删除末尾元素\n"); 
	SeqListPopback(&sl);
	printf("打印数组\n"); 
	SeqListPrint(&sl);
	
	printf("删除开头元素\n"); 
	SeqListPopFront(&sl);
	printf("打印数组\n"); 
	SeqListPrint(&sl); 
	
	printf("在指定位置插入,例如在第3位插入数字12\n"); 
	SeqListInsert(&sl, 3, 12); 
	printf("打印数组\n"); 
	SeqListPrint(&sl); 
	
	printf("在指定位置删除,例如在第3位删除数字12\n"); 
	SeqListErase(&sl, 3, 12); 
	printf("打印数组\n"); 
	SeqListPrint(&sl); 
	
	printf("查找指定元素,返回顺序表所在位置,未找到返回-1\n"); 
	printf("查找元素3\n"); 
	printf("%d\n",SeqListFind(&sl, 3));
	printf("查找元素0\n");
	printf("%d\n",SeqListFind(&sl, 0));
	
	return 0;
	
	
	
}
