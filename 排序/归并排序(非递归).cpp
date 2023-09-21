# include<stdio.h>
# include<stdlib.h> 
/*
归并排序非递归 
1、使用循环方式  
2、边界修正最麻烦  


*/


void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	// 每组数据个数  
	int gap = 1;
	// 1，2，4，8归并  
	while(gap < n)
	{
		
		for(int i=0;i<n;i+=2*gap)
		{
			int begin1 = i;
			int end1 = i + gap - 1;
			
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;
			
			// 归并过程中右半区间可能就不存在 
			if(begin2 >= n)
			{
				break;
			} 
			// 归并过程中右半区间算多了，需要修正  
			if(end2 >= n)
			{
				end2 = n - 1;	
			} 
			
			int index = i;
			
			// 选小的循环录入  
			while(begin1 <= end1 && begin2 <= end2)
			{
				if(a[begin1] < a[begin2])
				{
					tmp[index++]= a[begin1++];
				}
				else
				{
					tmp[index++]= a[begin2++];
				}
			}
			
			//  将剩下的录入  
			while(begin1 <= end1)
			{
				tmp[index++]= a[begin1++];
			}
			while(begin2 <= end2)
			{
				tmp[index++]= a[begin2++];
			}
			// 拷贝回去 
			for(int j=0;j<=end2;j++)
			{
				a[j] = tmp[j];
			} 
		}
		
		gap = gap * 2;
	}
	free(tmp);
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
	int a[]={3,5,2,7,8,6,1,9,4,0,0};
	int len = sizeof(a)/sizeof(a[0]); 
	MergeSortNonR(a, len);
	Print(a, len);
	
	return 0;
	 
} 
