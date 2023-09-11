# include<stdio.h>
# include<assert.h>
# include<stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data; 
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail; 
}Queue; 


// 初始化 
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

// 创建节点 
QNode* createNode(QDataType x)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if(newnode == NULL)
	{
		printf("malloc 失败"); 
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	
	return newnode;
}

// 销毁 
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while(cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
	 
}

// 判空 
bool QueueEmpty(Queue* pq)
{
	return pq->head == NULL && pq->tail == NULL; 
} 

// 插入 
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq); 
	// 创建节点 
	QNode* newnode = createNode(x); 
	if(pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode; 
	}	
}

// 删除 
void QueuePop(Queue* pq)
{
	assert(pq);
	// 防止pq->head为空 
	assert(!QueueEmpty(pq));

	QNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if(pq->head == NULL)
	{
		pq->tail = NULL; 
	}
	
} 

// 取队头 
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq)); 
	return pq->head->data;
}

// 取队尾 
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
	
}

// 元素个数 
int QueueSize(Queue* pq)
{
	assert(pq);
	int sum = 0;
	QNode* cur = pq->head;
	while(cur)
	{
		sum++;
		cur = cur->next;
	}
	return sum;
} 

// 遍历 
void QueuePrint(Queue* pq)
{
	QNode* cur = pq->head;

	while(cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
} 

int main()
{
	Queue q;
	QueueInit(&q);
	
	// 入队 
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	
	// 出队 
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	
	// 打印 
	QueuePrint(&q);
	
	// 取队头 
	printf("%d\n", QueueFront(&q));
	
	// 取队尾 
	printf("%d\n", QueueBack(&q)); 
	
	// 个数
	printf("%d\n", QueueSize(&q)); 
	
 
	
	return 0; 
	
} 


