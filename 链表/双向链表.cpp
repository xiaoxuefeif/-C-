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

// ��ͷ���Ϳ��Բ�ʹ�ö���ָ��  
// ��ʼ�� 
LTNode* ListInit()
{
	// ��Ϊ�ڱ�λ��ͷ�ڵ㣬���洢��Ч��Ϣ 
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	
	return phead;	  
}

// �����½ڵ� 
LTNode* CreateListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	
	return newnode;	
} 

// β�� 
void ListPushBack(LTNode* phead, LTDataType x)
{
	
	// �����µĽڵ� 
	LTNode* newnode =  CreateListNode(x);
	
	// ��һ���ڱ�λ��ͷ�ڵ㣬˫��ѭ��������Ҫ���ǿ���������� 
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;	
}

// βɾ 
void ListPopBack(LTNode* phead)
{
	// ��ʾ����Ϊ�գ�����ɾ  
	assert(phead->next != phead);
	
	// Ѱ��β�ڵ� 
	LTNode* tail = phead->prev;
	
	tail->prev->next = phead;
	tail->prev = phead->prev;
	
} 

// ͷ�� 
void ListPushFront(LTNode* phead, LTDataType x)  
{
	// �����µĽڵ� 
	LTNode* newnode =  CreateListNode(x);
	
	LTNode* head = phead->next;
	newnode->next = head;
	head->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;
}

// ͷɾ 
void ListPopFront(LTNode* phead) 
{
	// ����� 
	assert(phead->next != phead); 
	
	// Ѱ��ͷ�ڵ� 
	LTNode* head = phead->next;
	
	phead->next = head->next;
	head->next->prev = phead;
}

// �ҽڵ� 
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

// ��posλ��֮ǰ���� (ͷ�壺posΪ phead->next; β�壺posΪ phead)
void ListInsert(LTNode* pos, LTDataType x) 
{
	assert(pos);
	// �����µĽڵ� 
	LTNode* newnode =  CreateListNode(x);
	
	// �ҵ�posλ��֮ǰ�Ľڵ� 
	LTNode* posPrev = pos->prev;
	
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
		
}

// ɾ��posλ�� 
void ListErase(LTNode* pos)
{
	assert(pos);
	
	// �ҵ�posλ��֮ǰ�Ľڵ� 
	LTNode* posPrev = pos->prev;
	
	posPrev->next = pos->next;
	pos->next->prev = posPrev;
		
}

// ���� 
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

// ��ӡ 
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
	// ���� 
	LTNode* phead = ListInit();
	
	// β�� 
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPushBack(phead, 5);
	
	// ͷ�� 
	ListPushFront(phead,6);
	ListPushFront(phead,7);
	ListPushFront(phead,8);
	ListPushFront(phead,9);
	ListPushFront(phead,10);
		
	// ��ӡ 
	Listprint(phead);
	
	// �ҵ�data = 1��λ�ã�Ȼ����data֮ǰ����5
	LTNode* findnode = ListFind(phead, 1);
	ListInsert(findnode, 5); 
	Listprint(phead);
	
	// ɾ��posλ�õĽڵ�
	findnode = ListFind(phead, 5);
	ListErase(findnode); 
	Listprint(phead);
	
	// ʹ��ListInsert����β���ͷ�� 
	ListInsert(phead, 6);
	ListInsert(phead->next, 11);
	Listprint(phead);
	 
	
	return 0;
	
}
 

 

 
