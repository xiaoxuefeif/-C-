# include<stdio.h>
/*
��������  

*/


void QuickSort_demo(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	// ��λ  
	int pivot = begin;
	int key = a[begin];
	
	while(begin < end)
	{
		// �ұ���С���ŵ���� 
		// begin < end ��ֹԽ��Ѱ��  
		while(begin < end && a[end] >= key)
		{
			end--;
		} 
		// С�ķŵ���ߵĿ���,�Լ��γ����µĿ�λ  
		a[pivot] = a[end];
		pivot = end;
		
		// ����Ҵ󣬷ŵ��ұ�  
		while(begin < end && a[begin] <= key)
		{
			begin++;
		} 
		a[pivot] = a[begin];
		pivot = begin;
		
	}
	pivot = begin;
	a[pivot] = key;
	
}

// ����  
void QuickSort(int* a, int left, int right)
{
	// �ݹ�������� 
	if(left >= right)
	{
		return ;
	} 
	
	int begin = left;
	int end = right-1;
	// �ڿ�  
	int pivot = begin;
	int key = a[begin];
	
	while(begin < end)
	{
		while(begin < end && a[end] >= key)
		{
			end--;
		}
		a[pivot] = a[end];
		pivot = end;
		
		while(begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[pivot] = a[begin];
		pivot = begin;	
	} 
	a[pivot] = key;
	
	// ��ʼ�ݹ� 
	QuickSort(a, left, pivot-1);
	QuickSort(a, pivot+1, right); 
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
	QuickSort(a, 0, len);
	Print(a, len);
	
	return 0;
	 
} 


