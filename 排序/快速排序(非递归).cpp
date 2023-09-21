# include<stdio.h>
# include<stdlib.h>
# include<assert.h>
# include<stdbool.h>
/*
��������ķǵݹ����  
�ݹ���ջ���  
�ݹ�ķǵݹ飺
1��ֱ�Ӹ�ѭ�����򵥣�
2���������ݽṹ��ջģ��ݹ���̣�����һ�㣩 

*/

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;       // ջ�� 
	int capacity;  // ���� 
}ST;


// ��ʼ��
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
} 


// ���� 
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;	
} 

// ��ջ 
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	// �жϿռ��Ƿ����  
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

// �п� (��Ϊ true, �ǿ�Ϊ false)
bool StackEmpty(ST* ps)
{
	assert(ps);
	
	return ps->top == 0; 	
} 

// ��ջ 
void StackPop(ST* ps)
{
	assert(ps);
	// ��ֹ ps->topΪ��  
	assert(!StackEmpty(ps));
	
	(ps->top)--;
	
} 
 
// ȡջ��Ԫ��  
STDataType StackTop(ST* ps) 
{
	assert(ps);
	// ��ֹ ps->topΪ��  
	assert(!StackEmpty(ps));
	
	return ps->a[ps->top - 1];	
}

// ջ�����ݶ���
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;	
}


// �ڿӷ�  
int PartSort_1(int* a, int left, int right)
{
	// �ڿ�ѡ����ȡ��  
//	int index = GetMidIndex(a, left, right);
//	Swap(&a[index], &a[left]); 
	
	int begin = left;
	int end = right;
	// �ڿ�  
	int pivot = begin;
	int key = a[begin];
	
	while(begin < end)
	{
		// �ұ���С  
		while(begin < end && a[end] >= key)
		{
			end--;
		}
		a[pivot] = a[end];
		pivot = end;
		
		// ����Ҵ� 
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
	// ����ȳ�  
	StackPush(&st, n-1);
	StackPush(&st, 0);
	
	while(!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);
		
		int right = StackTop(&st);
		StackPop(&st);
	
		int keyIndex = PartSort_1(a, left, right); 
		// �ȴ����� �ٴ����� 
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

// ��ӡ�����뽫����ĳ��ȴ���  
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





