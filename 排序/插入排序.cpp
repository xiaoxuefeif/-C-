# include<stdio.h>

/*
 �������� 
 ÿ����һ��Ԫ�أ�ԭ���ж����Ѿ��ź���� 

*/ 
void InsertSort(int* a, int n)
{
	// n-1����Ϊ������Ԫ�ض�����end֮����룬end��Զ��n-2��λ�� 
	for(int i=0;i<n-1;i++)
	{
		                       // ÿһ������Ĵ���
		int end = i;
		                       // ����������ֵ����ֹ������
		int tmp = a[end+1];
		// ѭ���ж�
		while(end >= 0)
		{
			// ����Ҫ��ֱ�ӽ����������� 
			if(a[end] > tmp)
			{
				a[end+1] = a[end];
				end--; 
			}
			else
			{
				// ������ֱ���˳� 
				break;
			} 
		} 
		// ��������������뵽���� 
		a[end+1] = tmp;
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
	int a[]={1,3,5,6,4,3,2};
	int len = sizeof(a)/sizeof(a[0]); 
	InsertSort(a, len);
	Print(a, len);
	
	return 0;
	 
} 
