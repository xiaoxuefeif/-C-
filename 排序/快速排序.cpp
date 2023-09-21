# include<stdio.h>
/*
快速排序 O(nlogn)
有序情况最坏 O(n^2) 

*/

// 一次遍历  
void QuickSort_demo(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	// 坑位  
	int pivot = begin;
	int key = a[begin];
	
	while(begin < end)
	{
		// 右边找小，放到左边 
		// begin < end 防止越界寻找  
		while(begin < end && a[end] >= key)
		{
			end--;
		} 
		// 小的放到左边的坑里,自己形成了新的坑位  
		a[pivot] = a[end];
		pivot = end;
		
		// 左边找大，放到右边  
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

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
} 

// 解决最坏情况: 三数取中  
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if(a[left] < a[mid])
	{
		if(a[mid] < a[right])
		{
			return mid;
		}
		else if(a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if(a[mid] > a[right])
		{
			return mid;
		}
		else if(a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

// 挖坑法  
int PartSort_1(int* a, int left, int right)
{
	// 挖坑选三数取中  
	int index = GetMidIndex(a, left, right);
	Swap(&a[index], &a[left]); 
	
	int begin = left;
	int end = right;
	// 挖坑  
	int pivot = begin;
	int key = a[begin];
	
	while(begin < end)
	{
		// 右边找小  
		while(begin < end && a[end] >= key)
		{
			end--;
		}
		a[pivot] = a[end];
		pivot = end;
		
		// 左边找大 
		while(begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[pivot] = a[begin];
		pivot = begin;	
	} 
	a[pivot] = key;
	
	return pivot; 
}


// 分治  
void QuickSort(int* a, int left, int right)
{
	// 递归结束条件 
	if(left >= right)
	{
		return ;
	} 
	
	// 挖坑法 
	int keyIndex = PartSort_1(a, left, right);
	 
	
	// 开始递归 
	QuickSort(a, left, keyIndex-1);
	QuickSort(a, keyIndex+1, right); 
}




// 打印：必须将数组的长度传入  
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
	QuickSort(a, 0, len-1);
	Print(a, len);
	
	return 0;
	 
} 

