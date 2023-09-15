# include<stdio.h>

/*
 插入排序，时间复杂度O(n^2)
 每插入一个元素，原序列都是已经排好序的 

*/ 
void InsertSort(int* a, int n)
{
	// n-1是因为待排序元素都是在end之后插入，end永远在n-2的位置 
	for(int i=0;i<n-1;i++)
	{
		                       // 每一次排序的次数
		int end = i;
		                       // 保存待排序的值，防止被覆盖
		int tmp = a[end+1];
		// 循环判断
		while(end >= 0)
		{
			// 满足要求直接将数组往后移 
			if(a[end] > tmp)
			{
				a[end+1] = a[end];
				end--; 
			}
			else
			{
				// 不满足直接退出 
				break;
			} 
		} 
		// 将待排序的数插入到数组 
		a[end+1] = tmp;
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
	InsertSort(a, len);
	Print(a, len);
	
	return 0;
	 
} 
