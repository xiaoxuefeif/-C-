# include<stdio.h>

/*冒泡排序 O(n^2) 


*/


void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(int* a, int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				Swap(&a[j], &a[j+1]);	
			}
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
	int a[]={3,5,2,7,8,6,1,9,4,0};
	int len = sizeof(a)/sizeof(a[0]); 
	BubbleSort(a, len);
	Print(a, len);
	
	return 0;
	 
} 
