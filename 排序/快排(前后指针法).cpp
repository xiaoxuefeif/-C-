# include<stdio.h>
/*
前后指针法 
 

*/
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
} 

// 解决最坏情况: 三数取中  
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + (right - left)) / 2;
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

void PartSort(int* a, int left, int right)
{	

	if(left >= right)
	{
		return ;
	}
	// 三数取中  
	int index = GetMidIndex (a, left, right); 
	Swap(&a[index], &a[left]);

	int prev = left;
	int cur = left + 1;
	int key = left;
	
	while(cur <= right)
	{
		// cur找小 
		if(a[cur] < a[key])
		{
			prev++;
			Swap(&a[cur], &a[prev]);
		}
		cur++; 	
	}
	Swap(&a[key], &a[prev]);
	
	PartSort(a, left, prev-1);
	PartSort(a, prev+1, right);
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
	PartSort(a, 0, len-1);
	Print(a, len);
	
	return 0;
	 
} 




