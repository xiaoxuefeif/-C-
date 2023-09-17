# include<stdio.h>

/*
ϣ������ 
ֱ���ڲ�������Ļ����ϵ��Ż� 
1���Ƚ���Ԥ����������ӽ�����
2��ֱ�Ӳ������� 
3��gap == 1 ����ֱ�Ӳ������� 
4��ʱ�临�Ӷȣ�O(N*log2^N) 

*/

void ShellSort(int* a, int n)
{
	// gap��ѡ�� 
	int gap = n; 
	while(gap > 1)
	{
		// �����Ϊ 1
		gap = gap / 2;            
		for(int i=0; i<n-gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while(end >= 0)
			{
				if(a[end] > tmp)
				{
					a[end + gap] = a[end];
					end = end - gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;	
	}
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
	ShellSort(a, len);
	Print(a, len);
	
	return 0;
	 
} 
