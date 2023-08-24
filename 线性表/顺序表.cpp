# include<stdio.h> 
# include<stdlib.h>
# include<string.h>
# include<math.h>
# include<stdbool.h>
# include<assert.h>
# include<ctype.h>

typedef int SLDataType;

// ��̬˳���
typedef struct SeqList
{
	SLDataType* a;
	int size;      // ��Ч���ݸ��� 
	int capacity;  // �����ռ��С	
}SL;

// �ӿں���
// 1.��ʼ������ 
void SeqListInit(SL*ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;	
} 

// ���ݺ��� 
void SeqListCheckCapacity(SL* ps)
{
	if(ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2; 
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*newcapacity);
		if(tmp == NULL)
		{
			printf("����ʧ��\n");
			exit(-1); 
		}
		
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

// 2.��ĩβ����Ԫ�� 
void SeqListPushBack(SL* ps, SLDataType x)
{
	
	SeqListCheckCapacity(ps); 
	
	ps->a[ps->size] = x;
	ps->size++;
	
}

// 3.��ͷ����Ԫ�� 
void SeqListPushFront(SL* ps, SLDataType x)
{
	
	SeqListCheckCapacity(ps);
	
	// Ų������ 
	int end = ps->size-1;
	while(end>=0)
	{
		ps->a[end+1] = ps->a[end];
		end--;	
	} 
	ps->a[0] = x;
	ps->size++;
}

// 4.ɾ��ĩβԪ�� 
void SeqListPopback(SL* ps)
{
	
//	if(ps->size > 0)
//	{
//		ps->size--;
//	} 
	
	assert(ps->size > 0);
	ps->size--;
	
}

// 4.ɾ����ͷԪ�� 
void SeqListPopFront(SL* ps)
{
	int begin = 0;
	while(begin<ps->size)
	{
		ps->a[begin] = ps->a[begin+1];
		begin++; 
	}
	ps->size--;
	
}

// 5.����Ԫ�أ�����˳�������λ�� 
int SeqListFind(SL* ps, SLDataType x)
{
	for(int i=0;i<ps->size;i++)
	{
		if(ps->a[i] == x)
		{
			return i+1;
		}
	}
	return -1; 
}

// 6.��ָ��λ�ò���
int SeqListInsert(SL* ps, int pos, SLDataType x)
{
	if(pos <= 0) printf("����λ�ñ������0");
	SeqListCheckCapacity(ps);
	
	int end = ps->size - 1;
	while(end >= pos-1)
	{
		ps->a[end+1] = ps->a[end];
		end--;	
	} 
	ps->a[pos-1] = x;
	ps->size++;
	return 1;
	 	
} 

// 7.��ָ��λ��ɾ�� 
int SeqListErase(SL* ps, int pos, SLDataType x)
{
	if(pos <= 0) printf("ɾ��λ�ñ������0");
	
	int begin = pos;
	while(begin < ps->size)
	{
		ps->a[begin-1] = ps->a[begin];
		begin++;	
	} 
	ps->size--;
	return 1;
		
} 

// ��ӡ 
void SeqListPrint(SL* ps)
{
	for(int i=0;i<ps->size;i++)
	{
		printf("%d ",ps->a[i]);
	}
	printf("\n"); 
} 




int main()
{
	SL sl;
	SeqListInit(&sl);
	printf("��ĩβ����1��3��5��7��9\n"); 
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 9);	
	printf("��ӡ����\n"); 
	SeqListPrint(&sl);
	
	printf("��ͷ����2��4��6��8��10\n"); 
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 6);
	SeqListPushFront(&sl, 8);
	SeqListPushFront(&sl, 10);	
	printf("��ӡ����\n"); 
	SeqListPrint(&sl);
	
	printf("ɾ��ĩβԪ��\n"); 
	SeqListPopback(&sl);
	printf("��ӡ����\n"); 
	SeqListPrint(&sl);
	
	printf("ɾ����ͷԪ��\n"); 
	SeqListPopFront(&sl);
	printf("��ӡ����\n"); 
	SeqListPrint(&sl); 
	
	printf("��ָ��λ�ò���,�����ڵ�3λ��������12\n"); 
	SeqListInsert(&sl, 3, 12); 
	printf("��ӡ����\n"); 
	SeqListPrint(&sl); 
	
	printf("��ָ��λ��ɾ��,�����ڵ�3λɾ������12\n"); 
	SeqListErase(&sl, 3, 12); 
	printf("��ӡ����\n"); 
	SeqListPrint(&sl); 
	
	printf("����ָ��Ԫ��,����˳�������λ��,δ�ҵ�����-1\n"); 
	printf("����Ԫ��3\n"); 
	printf("%d\n",SeqListFind(&sl, 3));
	printf("����Ԫ��0\n");
	printf("%d\n",SeqListFind(&sl, 0));
	
	return 0;
	
	
	
}
