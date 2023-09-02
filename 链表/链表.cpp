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


// ����һ���ڵ�
SN* CreateSListNode(SLDataType x)
{
	SN* newnode = (SN*)malloc(sizeof(SN));
	newnode->data = x;
	newnode->next = NULL;
	
	return newnode;
}

// ��ӡ���� 
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

// ��β������ 
void  SListPushBack(SN** phead, SLDataType x)
{
	// �ȴ����½ڵ� 
	SN* newnode = CreateSListNode(x);
	// �ж�pead�Ƿ�Ϊ NULL,�������û���κνڵ� 
	if(*phead == NULL)
	{
		*phead = newnode;		
	} 
	else
	{
		SN* tail = *phead;
		// �ҵ�β�ڵ� 
		while(tail->next != NULL)
		{
			tail = tail->next;
		}	
		tail->next = newnode;
	}
	
} 

// ��ͷ������
void SListPushFront(SN** phead, SLDataType x)
{
	// �ȴ����½ڵ� 
	SN* newnode = CreateSListNode(x);
	
	// �ж�pead�Ƿ�Ϊ NULL,�������û���κνڵ� 
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

// βɾ 
void SListPopBack(SN** phead)
{
	// ͷ�ڵ�Ϊ�� 
	if(*phead == NULL)
	{
		return;	
	} 
	
	// ֻ��һ���ڵ� 
	if((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL; 
	} 
	else
	{
		SN* prev = NULL; 
		SN* tail = *phead;
		// �ҵ����һ���ڵ� 
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

// ͷɾ 
void SListPopFront(SN** phead)
{
	// ͷ�ڵ�Ϊ�� 
	if(*phead == NULL)
	{
		return;	
	} 
	
	// ֻ��һ���ڵ� 
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

// ����ĳ��Ԫ��(����Ҫ����ĳ��Ԫ��,ʹ��һ��ָ��)
// �õ���ַ��Ҳ���޸ĸýڵ��ֵ������  
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

// ��posλ��֮ǰȥ����һ���ڵ� 
void SListInsertBefore(SN** phead, SN* pos, SLDataType x)
{
	// �ж� pos �Ƿ�Ϊ�׽�� 
	if(*phead == pos)
	{
		SListPushFront(&(*phead), x);
	}
	else
	{
		// �ȴ����½ڵ� 
		SN* newnode = CreateSListNode(x);
		// �ҵ� pos ֮ǰ�Ľڵ�λ��
		SN* posPrev = *phead;
		while(posPrev->next != pos)
		{
			posPrev = posPrev->next;
		} 
		posPrev->next = newnode;
		newnode->next = pos;
	} 
	
}

// ��posλ��֮��ȥ����һ���ڵ� 
void SListInsertAfter(SN** phead, SN* pos, SLDataType x)
{

	SN* newnode = CreateSListNode(x);
	// �ҵ� pos ��ǰλ�� 
	SN* cur = *phead;
	while(cur != pos)
	{
		cur = cur->next;
	}
	newnode->next = cur->next;
	cur->next = newnode;
	 
}

// ɾ�� posλ�õĽڵ� 
void SListErase(SN** phead, SN* pos)
{
	// ֻ��һ���ڵ� 
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

// ɾ�� pos ֮��Ľڵ� 
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

// �������� 
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
	
	// β�� 
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	
	// ͷ�� 
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);

	// βɾ 
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	
	// ͷɾ 
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	
	// ��ӡ  
	SListPrint(plist);
	
	// 1.�� 
	SN* pos = SListFind(plist, 2);
	int i=1;
	while(pos)
	{
		printf("��%d��pos���:%p->%d\n",i++,pos,pos->data);
		pos = SListFind(pos->next, 2);
	}
	// 2.�޸� 
	pos = SListFind(plist, 2);
	if(pos)
	{
		pos->data = 3;
		// �� 3 ��ǰ�����һ�� 30
		SListInsertBefore(&plist, pos, 30); 
		SListInsertAfter(&plist, pos, 20);
	}	
	SListPrint(plist);
		
	// ɾ��ĳ��λ�õĽڵ�  
	pos = SListFind(plist, 30);
	SListErase(&plist, pos); 	
	SListPrint(plist);
	
	// ɾ��ĳ��λ��֮��Ľڵ� 
	pos = SListFind(plist, 3); 
	SListEraseAfter(&plist, pos); 
	SListPrint(plist);
	
	// ��������
	 
	
	return 0;
}


