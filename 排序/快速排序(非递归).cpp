# include<stdio.h>
# include<stdlib.h>
# include<assert.h>
# include<stdbool.h>
/*
快速排序的非递归操作  
递归版会栈溢出  
递归改非递归：
1、直接改循环（简单）
2、借助数据结构的栈模拟递归过程（复杂一点） 

*/

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;       // 栈顶 
	int capacity;  // 容量 
}ST;


// 初始化
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
} 


// 销毁 
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;	
} 

// 入栈 
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	// 判断空间是否充足  
	if(ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType)*(newCapacity)); 
		if(tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		
		ps->a = tmp;
		ps->capacity = newCapacity;	
	} 
	
	ps->a[ps->top] = x;
	ps->top++;
}

// 判空 (空为 true, 非空为 false)
bool StackEmpty(ST* ps)
{
	assert(ps);
	
	return ps->top == 0; 	
} 

// 出栈 
void StackPop(ST* ps)
{
	assert(ps);
	// 防止 ps->top为空  
	assert(!StackEmpty(ps));
	
	(ps->top)--;
	
} 
 
// 取栈顶元素  
STDataType StackTop(ST* ps) 
{
	assert(ps);
	// 防止 ps->top为空  
	assert(!StackEmpty(ps));
	
	return ps->a[ps->top - 1];	
}

// 栈中数据多少
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;	
}


// 挖坑法  
int PartSort_1(int* a, int left, int right)
{
	// 挖坑选三数取中  
//	int index = GetMidIndex(a, left, right);
//	Swap(&a[index], &a[left]); 
	
	int begin = left;
	int end = right;
	// 挖坑  
	int pivot = begin;
	int key = a[begin];
	
	while(begin < end)
	{
		// 右边找小  
		while(begin < end && a[end] >= key)
		{
			end--;
		}
		a[pivot] = a[end];
		pivot = end;
		
		// 左边找大 
		while(begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[pivot] = a[begin];
		pivot = begin;	
	} 
	a[pivot] = key;
	
	return pivot; 
}

void QuickSortNonR(int* a, int n) 
{
	ST st;
	StackInit(&st);
	// 后进先出  
	StackPush(&st, n-1);
	StackPush(&st, 0);
	
	while(!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);
		
		int right = StackTop(&st);
		StackPop(&st);
	
		int keyIndex = PartSort_1(a, left, right); 
		// 先处理左， 再处理右 
		if(keyIndex+1 < right) 
		{
			StackPush(&st, right);
			StackPush(&st, keyIndex+1);
		}
		if(left < keyIndex-1)
		{
			StackPush(&st, keyIndex-1);
			StackPush(&st, left);
		}
	}
	
	StackDestroy(&st);
}

// 打印：必须将数组的长度传入  
void Print(int* a, int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	} 
	printf("\n");
}


int main()
{ 
	int a[]={3,5,2,7,8,6,1,9,4,0};
	int len = sizeof(a)/sizeof(a[0]); 
	QuickSortNonR(a, len);
	Print(a, len);
	
	return 0; 
}





