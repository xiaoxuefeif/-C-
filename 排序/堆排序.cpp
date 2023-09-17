# include<stdio.h>

/*
������ (ѡ�������һ��)
1.���µ����㷨 (ǰ�᣺����������Ϊ��(С)��) 
2.���������������(С)�ѣ��Ͳ���ʹ�����µ����㷨
2.1 ������������Ŵ����һ��������ʼ��,�����һ����Ҷ�ӵ�������ʼ�� 
              ֪�����Ҷ�ӽڵ��±�Ϊ n-1,�Ҹ�Ҷ�ӽڵ�ĸ���: (n-1-1)/2 
 
 
*/ 
 
void Swap(int* a, int* b)
{
	*a = *a ^ *b; 
	*b = *a ^ *b; 
	*a = *a ^ *b; 
} 

void AdjustDown(int* a, int n, int root)
{
	// ��С�Ѿ��� 
	int parent = root;
	int child = parent * 2 + 1; // Ĭ������
	while(child < n)
	{
		// ѡ�����Һ����д����һ��,child+1<n��Ϊ�˷�ֹ���պñ���������û���Һ��� 
		// Ҫ����Ѿ���Ҫ a[child+1] > a[child], a[child] > a[parent]
		if(child+1 < n && a[child+1] > a[child])
		{
			child++;
		} 
		if(a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;	 
		}
		else
		{
			break;
		}
	} 
} 

void HeapSort(int* a, int n)
{
	// �����齨�ɴ�ѻ�С�� 
	for(int i=(n-1-1)/2; i>=0; i--)
	{
		AdjustDown(a, n, i);
	}
	// �����򽨴��,����С�� 
	int end = n-1;
	while(end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	} 
	 
	
}

// ���뽫����ĳ��ȴ���  
void Print(int* a, int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	} 
	printf("\n");
}



int main()
{ 
	int a[]={3,5,2,7,8,6,1,9,4,0};
	int len = sizeof(a)/sizeof(a[0]); 
	HeapSort(a, len);
	Print(a, len);
	
	return 0;
	 
} 

 
