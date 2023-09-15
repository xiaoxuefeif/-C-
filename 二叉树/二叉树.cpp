# include<stdio.h>
# include<stdlib.h>
# include<assert.h>

// ������  
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data; 
} BTNode;

// �����ڵ� 
BTNode* createNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = x;
	
	return newnode;  
} 

// ǰ�򣨸����ң� 
void PreOrder(BTNode* root)
{
	if(root == NULL)
	{
		return ;
	}
	printf("%d ",root->data);
	PreOrder(root->left);
	PreOrder(root->right); 
}

// ��������ң� 
void InOrder(BTNode* root)
{
	if(root == NULL)
	{
		return ;
	}
	InOrder(root->left);
	printf("%d ",root->data);
	InOrder(root->right);
	
}

// �������Ҹ��� 
void PostOrder(BTNode* root)
{
	if(root == NULL)
	{
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

// �ܽڵ���� �����Σ� 
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
	
}

// Ҷ�ӽڵ����
int TreeLeafSize(BTNode* root)
{
	if(root == NULL)
	{
		return 0;
	}
	if(root->left==NULL && root->right==NULL)
	{
		return 1;
	} 
	return TreeLeafSize(root->left)+TreeLeafSize(root->right);
} 

int maxDepth(BTNode* root){
    if(root == NULL)
    {
        return 0;
    }
    int left =  maxDepth(root->left);
    int right =  maxDepth(root->right);
    return left > right ? left+1 : right+1;

}

// **********************************************************************************
// ���ض��� 
typedef BTNode* QDataType;

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
 
// ������� ��������ȣ�
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	// �����һ���ڵ�  
	if(root)
	{
		QueuePush(&q, root);
	}
	
	while(!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", front->data);	
		// ��Ϊ��  
		if(front->left)
		{
			QueuePush(&q, front->left);
		}
		
		// �Ҳ�Ϊ��  
		if(front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	
} 


int main()
{
	BTNode* A = createNode(1);
	BTNode* B = createNode(2);
	BTNode* C = createNode(3);
	
	A->left = B;
	A->right = C;
	
	// ǰ�к������ 
	PreOrder(A); 
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");
	
	// ȫ���ڵ� 
	printf("%d", TreeSize(A));
	printf("\n");
	// Ҷ�ӽڵ� 
	printf("%d", TreeLeafSize(A));
	printf("\n");
	
	// ������� 
	LevelOrder(A);
	printf("\n"); 
	
	// ������� 
	printf("%d", maxDepth(A));
	printf("\n"); 
	
	return 0;		
}
