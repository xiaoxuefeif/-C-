# include<stdio.h>
# include<stdlib.h>
# include<assert.h>
# include<stdbool.h>

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
	ps->a == NULL;
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

// �п� (��Ϊtrue, �ǿ�Ϊfalse)
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

int main()
{
	ST st;
	StackInit(&st);
	
	// ѭ����ջ 
	int n = 5; 
	while(n)
	{
		StackPush(&st, n);
		n--;
	}
	
	// ѭ����ջ 
	while(!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	} 
	
	// ���� 
	StackDestroy(&st); 
	
	return 0;    	
} 


