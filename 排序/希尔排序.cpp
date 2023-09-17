# include<stdio.h>

/*
希尔排序 
直接在插入排序的基础上的优化 
1、先进行预排序，让数组接近有序
2、直接插入排序 
3、gap == 1 就是直接插入排序 
4、时间复杂度：O(N*log2^N) 

*/

void ShellSort(int* a, int n)
{
	// gap的选择 
	int gap = n; 
	while(gap > 1)
	{
		// 最后需为 1
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

// 必须将数组的长度传入  
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
