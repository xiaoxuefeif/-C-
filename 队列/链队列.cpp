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


// ��ʼ�� 
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

// �����ڵ� 
QNode* createNode(QDataType x)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if(newnode == NULL)
	{
		printf("malloc ʧ��"); 
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	
	return newnode;
}

// ���� 
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

// �п� 
bool QueueEmpty(Queue* pq)
{
	return pq->head == NULL && pq->tail == NULL; 
} 

// ���� 
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq); 
	// �����ڵ� 
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

// ɾ�� 
void QueuePop(Queue* pq)
{
	assert(pq);
	// ��ֹpq->headΪ�� 
	assert(!QueueEmpty(pq));

	QNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if(pq->head == NULL)
	{
		pq->tail = NULL; 
	}
	
} 

// ȡ��ͷ 
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq)); 
	return pq->head->data;
}

// ȡ��β 
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
	
}

// Ԫ�ظ��� 
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

// ���� 
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
	
	// ��� 
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	
	// ���� 
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	
	// ��ӡ 
	QueuePrint(&q);
	
	// ȡ��ͷ 
	printf("%d\n", QueueFront(&q));
	
	// ȡ��β 
	printf("%d\n", QueueBack(&q)); 
	
	// ����
	printf("%d\n", QueueSize(&q)); 
	
 
	
	return 0; 
	
} 


