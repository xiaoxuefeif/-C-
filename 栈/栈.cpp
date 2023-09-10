# include<stdio.h>
# include<stdlib.h>
# include<assert.h>
# include<stdbool.h>

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
	ps->a == NULL;
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

// 判空 (空为true, 非空为false)
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

int main()
{
	ST st;
	StackInit(&st);
	
	// 循环入栈 
	int n = 5; 
	while(n)
	{
		StackPush(&st, n);
		n--;
	}
	
	// 循环出栈 
	while(!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	} 
	
	// 销毁 
	StackDestroy(&st); 
	
	return 0;    	
} 


