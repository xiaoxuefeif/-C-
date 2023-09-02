# include<stdio.h> 
# include<stdlib.h>
# include<string.h>
# include<math.h>
# include<stdbool.h>
# include<assert.h>
# include<ctype.h>

typedef int SLDataType; 

typedef struct SlistNode
{
	SLDataType data;
	struct SlistNode* next;
}SN;


// 创建一个节点
SN* CreateSListNode(SLDataType x)
{
	SN* newnode = (SN*)malloc(sizeof(SN));
	newnode->data = x;
	newnode->next = NULL;
	
	return newnode;
}

// 打印链表 
void SListPrint(SN* phead)
{
	SN* tmp = phead;
	while(tmp != NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;	
	}
	printf("\n");
} 

// 在尾部插入 
void  SListPushBack(SN** phead, SLDataType x)
{
	// 先创建新节点 
	SN* newnode = CreateSListNode(x);
	// 判断pead是否为 NULL,检测链表没有任何节点 
	if(*phead == NULL)
	{
		*phead = newnode;		
	} 
	else
	{
		SN* tail = *phead;
		// 找到尾节点 
		while(tail->next != NULL)
		{
			tail = tail->next;
		}	
		tail->next = newnode;
	}
	
} 

// 在头部插入
void SListPushFront(SN** phead, SLDataType x)
{
	// 先创建新节点 
	SN* newnode = CreateSListNode(x);
	
	// 判断pead是否为 NULL,检测链表没有任何节点 
	if(*phead == NULL)
	{
		*phead = newnode;		
	} 
	else
	{
		newnode->next = *phead;
		*phead = newnode;
	}	
} 

// 尾删 
void SListPopBack(SN** phead)
{
	// 头节点为空 
	if(*phead == NULL)
	{
		return;	
	} 
	
	// 只有一个节点 
	if((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL; 
	} 
	else
	{
		SN* prev = NULL; 
		SN* tail = *phead;
		// 找到最后一个节点 
		while(tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		
		prev->next = NULL; 		
	}
} 

// 头删 
void SListPopFront(SN** phead)
{
	// 头节点为空 
	if(*phead == NULL)
	{
		return;	
	} 
	
	// 只有一个节点 
	if((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL; 
	} 
	else
	{
		SN* prev = (*phead)->next;
		free(*phead);
		*phead = prev;	
	}	
} 

// 查找某个元素(不需要更改某个元素,使用一级指针)
// 得到地址后也有修改该节点的值的作用  
SN* SListFind(SN* phead, SLDataType x)
{
	SN* cur = phead;
	while(cur)
	{
		if(cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
} 

// 在pos位置之前去插入一个节点 
void SListInsertBefore(SN** phead, SN* pos, SLDataType x)
{
	// 判断 pos 是否为首结点 
	if(*phead == pos)
	{
		SListPushFront(&(*phead), x);
	}
	else
	{
		// 先创建新节点 
		SN* newnode = CreateSListNode(x);
		// 找到 pos 之前的节点位置
		SN* posPrev = *phead;
		while(posPrev->next != pos)
		{
			posPrev = posPrev->next;
		} 
		posPrev->next = newnode;
		newnode->next = pos;
	} 
	
}

// 在pos位置之后去插入一个节点 
void SListInsertAfter(SN** phead, SN* pos, SLDataType x)
{

	SN* newnode = CreateSListNode(x);
	// 找到 pos 当前位置 
	SN* cur = *phead;
	while(cur != pos)
	{
		cur = cur->next;
	}
	newnode->next = cur->next;
	cur->next = newnode;
	 
}

// 删除 pos位置的节点 
void SListErase(SN** phead, SN* pos)
{
	// 只有一个节点 
	if(*phead == pos)
	{
//		*phead = pos->next;
//		free(pos);
		SListPopFront(&(*phead));
	}
	else
	{
		SN* pre = *phead;
		while(pre != pos)
		{
			pre = pre->next;
		}
		pre->next = pos->next;
		free(pos);
	} 	
}

// 删除 pos 之后的节点 
void SListEraseAfter(SN** phead, SN* pos)
{
	if(pos->next == NULL)
	{
		return;
	}
	else
	{
		SN* next = pos->next;
		pos->next = next->next;
		free(next);
	}
}

// 销毁链表 
void SListDestroy(SN** phead)
{
	SN* cur = *phead;
	while(cur)
	{
		free(cur);
		cur = cur->next;
	}
}


int main()
{
	SN* plist = NULL;
	
	// 尾插 
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	
	// 头插 
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);

	// 尾删 
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	
	// 头删 
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	
	// 打印  
	SListPrint(plist);
	
	// 1.找 
	SN* pos = SListFind(plist, 2);
	int i=1;
	while(pos)
	{
		printf("第%d个pos结点:%p->%d\n",i++,pos,pos->data);
		pos = SListFind(pos->next, 2);
	}
	// 2.修改 
	pos = SListFind(plist, 2);
	if(pos)
	{
		pos->data = 3;
		// 在 3 的前面插入一个 30
		SListInsertBefore(&plist, pos, 30); 
		SListInsertAfter(&plist, pos, 20);
	}	
	SListPrint(plist);
		
	// 删除某个位置的节点  
	pos = SListFind(plist, 30);
	SListErase(&plist, pos); 	
	SListPrint(plist);
	
	// 删除某个位置之后的节点 
	pos = SListFind(plist, 3); 
	SListEraseAfter(&plist, pos); 
	SListPrint(plist);
	
	// 销毁链表
	 
	
	return 0;
}


