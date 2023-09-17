# include<stdio.h>

/*
堆排序 (选择排序的一种)
1.向下调整算法 (前提：左右子树都为大(小)堆) 
2.如果左右子树不是(小)堆，就不能使用向下调整算法
2.1 解决方案：倒着从最后一颗子树开始调,从最后一个非叶子的子树开始调 
              知道最后叶子节点下标为 n-1,找该叶子节点的父亲: (n-1-1)/2 
 
 
*/ 
 
void Swap(int* a, int* b)
{
	*a = *a ^ *b; 
	*b = *a ^ *b; 
	*a = *a ^ *b; 
} 

void AdjustDown(int* a, int n, int root)
{
	// 以小堆举例 
	int parent = root;
	int child = parent * 2 + 1; // 默认左孩子
	while(child < n)
	{
		// 选出左右孩子中大的那一个,child+1<n是为了防止最后刚好遍历到左孩子没有右孩子 
		// 要建大堆就需要 a[child+1] > a[child], a[child] > a[parent]
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
	// 把数组建成大堆或小堆 
	for(int i=(n-1-1)/2; i>=0; i--)
	{
		AdjustDown(a, n, i);
	}
	// 排升序建大堆,降序建小堆 
	int end = n-1;
	while(end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
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
	HeapSort(a, len);
	Print(a, len);
	
	return 0;
	 
} 

 
