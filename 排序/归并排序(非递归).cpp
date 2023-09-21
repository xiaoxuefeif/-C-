# include<stdio.h>
# include<stdlib.h> 
/*
�鲢����ǵݹ� 
1��ʹ��ѭ����ʽ  
2���߽��������鷳  


*/


void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	// ÿ�����ݸ���  
	int gap = 1;
	// 1��2��4��8�鲢  
	while(gap < n)
	{
		
		for(int i=0;i<n;i+=2*gap)
		{
			int begin1 = i;
			int end1 = i + gap - 1;
			
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;
			
			// �鲢�������Ұ�������ܾͲ����� 
			if(begin2 >= n)
			{
				break;
			} 
			// �鲢�������Ұ���������ˣ���Ҫ����  
			if(end2 >= n)
			{
				end2 = n - 1;	
			} 
			
			int index = i;
			
			// ѡС��ѭ��¼��  
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
			
			//  ��ʣ�µ�¼��  
			while(begin1 <= end1)
			{
				tmp[index++]= a[begin1++];
			}
			while(begin2 <= end2)
			{
				tmp[index++]= a[begin2++];
			}
			// ������ȥ 
			for(int j=0;j<=end2;j++)
			{
				a[j] = tmp[j];
			} 
		}
		
		gap = gap * 2;
	}
	free(tmp);
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
	int a[]={3,5,2,7,8,6,1,9,4,0,0};
	int len = sizeof(a)/sizeof(a[0]); 
	MergeSortNonR(a, len);
	Print(a, len);
	
	return 0;
	 
} 
