# include<stdio.h>
/*
����ָ�뷨
 
*/

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
} 

// �������: ����ȡ��  
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
	// �ݹ��������
	if(left >= right)
	{
		return ;
	} 
	
	int index = GetMidIndex(a, left, right);
	Swap(&a[index], &a[left]);
	
	int begin = left;
	int end = right;
	int key = begin;
	
	while(begin < end)
	{
		while(begin < end && a[end] >= a[key])
		{
			end--;
		}
		while(begin < end && a[begin] <= a[key])
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[key]);
	
	PartSort(a, left, begin-1);
	PartSort(a, begin+1, right);	 
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
	int a[]={3,5,2,7,8,6,1,9,4,0};
	int len = sizeof(a)/sizeof(a[0]); 
	PartSort(a, 0, len-1);
	Print(a, len);
	
	return 0;
	 
} 
