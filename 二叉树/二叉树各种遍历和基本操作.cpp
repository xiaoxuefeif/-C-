# include<stdio.h>
# include<stdlib.h>
# include<assert.h>

// 二叉树  
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data; 
} BTNode;

// 创建节点 
BTNode* createNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = x;
	
	return newnode;  
} 

// 前序（根左右） 
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

// 中序（左根右） 
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

// 后序（左右根） 
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

// 总节点个数 （分治） 
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
	
}

// 叶子节点个数
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
// 加载队列 
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
 
// 层序遍历 （广度优先）
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	// 插入第一个节点  
	if(root)
	{
		QueuePush(&q, root);
	}
	
	while(!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", front->data);	
		// 左不为空  
		if(front->left)
		{
			QueuePush(&q, front->left);
		}
		
		// 右不为空  
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
	
	// 前中后序遍历 
	PreOrder(A); 
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");
	
	// 全部节点 
	printf("%d", TreeSize(A));
	printf("\n");
	// 叶子节点 
	printf("%d", TreeLeafSize(A));
	printf("\n");
	
	// 层序遍历 
	LevelOrder(A);
	printf("\n"); 
	
	// 树的深度 
	printf("%d", maxDepth(A));
	printf("\n"); 
	
	return 0;		
}
