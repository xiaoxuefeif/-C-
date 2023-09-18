# include<stdio.h>
/*
直接选择排序 O(n^2) 


*/

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
} 

void SelectSort(int* a, int n)
{
	int begin = 0, end = n-1;
	while(begin < end)
	{
		int min = begin;
		int max = begin;
		for(int i=begin; i<=end; i++)
		{
			if(a[i] < a[min])
			{
				min = i;
			}
			if(a[i] > a[max])
			{
				max = i;
			}
		}
		Swap(&a[begin], &a[min]);
		if(begin == max)
		{
			max = min;
		}
		Swap(&a[max], &a[end]);
		begin++;
		end--;
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
	int a[]={3,5,2,7,8,6,1,9,4,0};
	int len = sizeof(a)/sizeof(a[0]); 
	SelectSort(a, len);
	Print(a, len);
	
	return 0;
	 
} 
