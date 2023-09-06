# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<assert.h>


typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode; 

// 带头结点就可以不使用二级指针  
// 初始化 
LTNode* ListInit()
{
	// 作为哨兵位的头节点，不存储有效信息 
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	
	return phead;	  
}

// 创建新节点 
LTNode* CreateListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	
	return newnode;	
} 

// 尾插 
void ListPushBack(LTNode* phead, LTDataType x)
{
	
	// 创建新的节点 
	LTNode* newnode =  CreateListNode(x);
	
	// 有一个哨兵位的头节点，双向循环链表不需要考虑空链表的问题 
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;	
}

// 尾删 
void ListPopBack(LTNode* phead)
{
	// 表示链表为空，不能删  
	assert(phead->next != phead);
	
	// 寻找尾节点 
	LTNode* tail = phead->prev;
	
	tail->prev->next = phead;
	tail->prev = phead->prev;
	
} 

// 头插 
void ListPushFront(LTNode* phead, LTDataType x)  
{
	// 创建新的节点 
	LTNode* newnode =  CreateListNode(x);
	
	LTNode* head = phead->next;
	newnode->next = head;
	head->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;
}

// 头删 
void ListPopFront(LTNode* phead) 
{
	// 链表空 
	assert(phead->next != phead); 
	
	// 寻找头节点 
	LTNode* head = phead->next;
	
	phead->next = head->next;
	head->next->prev = phead;
}

// 找节点 
LTNode* ListFind(LTNode* phead, LTDataType x)
{
	LTNode* cur = phead->next;
	while(cur != phead)
	{
		if(cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	} 
	
	return NULL;	
} 

// 在pos位置之前插入 (头插：pos为 phead->next; 尾插：pos为 phead)
void ListInsert(LTNode* pos, LTDataType x) 
{
	assert(pos);
	// 创建新的节点 
	LTNode* newnode =  CreateListNode(x);
	
	// 找到pos位置之前的节点 
	LTNode* posPrev = pos->prev;
	
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
		
}

// 删除pos位置 
void ListErase(LTNode* pos)
{
	assert(pos);
	
	// 找到pos位置之前的节点 
	LTNode* posPrev = pos->prev;
	
	posPrev->next = pos->next;
	pos->next->prev = posPrev;
		
}

// 销毁 
void ListDestroy(LTNode* phead)
{
	LTNode* cur = phead;
	while(cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	
	free(phead);
	phead = NULL;
} 

// 打印 
void Listprint(LTNode* phead) 
{
	LTNode* cur = phead->next;
	while(cur != phead)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	} 
	printf("\n");
}



int main()
{
	// 创建 
	LTNode* phead = ListInit();
	
	// 尾插 
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPushBack(phead, 5);
	
	// 头插 
	ListPushFront(phead,6);
	ListPushFront(phead,7);
	ListPushFront(phead,8);
	ListPushFront(phead,9);
	ListPushFront(phead,10);
		
	// 打印 
	Listprint(phead);
	
	// 找到data = 1的位置，然后在data之前插入5
	LTNode* findnode = ListFind(phead, 1);
	ListInsert(findnode, 5); 
	Listprint(phead);
	
	// 删除pos位置的节点
	findnode = ListFind(phead, 5);
	ListErase(findnode); 
	Listprint(phead);
	
	// 使用ListInsert进行尾插和头插 
	ListInsert(phead, 6);
	ListInsert(phead->next, 11);
	Listprint(phead);
	 
	
	return 0;
	
}
 

 

 
