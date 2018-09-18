#include<stdio.h>
#include<malloc.h>
#include"rank.h"

void swap(int* a, int i, int j)
{
	int tmp=0;
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void display(int* a,int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d", a[i]);
		printf(" ");
	}
	printf("\n");
}

//顺序排序
void order_rank(int* a,int len)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < len; i++)
	{
		k = i;
		for (j = i+1 ; j < len; j++)
		{
			if (a[j] < a[k])
			{
				k = j;
			}
		}
		swap(a, i,k);
	}
	display(a, len);
}

//冒泡【排序
void bubbling_rank(int *a,int len)
{
	int i = 0;
	int j = 0;
	int k = 1;
	for (i = 0; i <len&&k ; i++)
	{
		k = 0;
		for (j = len-1; j > i; j--)
		{
			if (a[j] < a[j-1])
			{
				k = 1;
				swap(a, j-1, j);
			}
		}
		
	}
	display(a, len);
}

//希尔排序
void  shell_insert_rank(int* a, int len)
{
	int i = 0;
	int j = 0;
	int k = -1;
	int temp = -1;
	int gap = len;
	do
	{
		gap = gap / 3 + 1; //取值为3比较好
		for (i = gap; i < len; i+=gap)
		{
			k = i;
			temp = a[i];
			for (j = i - gap; (j >= 0) && (a[j] > temp); j-=gap)
			{
				a[j + gap] = a[j];
				k = j;
			}
			a[k] = temp;
		}
	} while (gap > 1);
	display(a, len);
}

//快速排序
int location_rank(int* a, int head, int end)
{
	int position;
	position = a[0];
	while (head < end)
	{
		while ((head < end) && (a[end] >= position))
		{
			end--;
		}
		swap(a, head,end);
		while ((head < end) && (a[head] <= position))
		{
			head++;
		}
		swap(a, head, end);
	}
	return head;
}

void repeat_rank(int*a, int head, int end)
{
	if (head < end)
	{
		int position = location_rank(a, head, end);
		repeat_rank(a, position + 1, end);
		repeat_rank(a, head, position - 1);
    }
}

void quick_rank(int* a,int head,int end)
{
	repeat_rank(a,head,end-1);
	display(a, end);
}

//2路归并排序
void Merge_rank(int* src, int* des, int head, int mid, int end)
{
	int i = head;
	int j = mid + 1;
	int k = head;

	while ((i <= mid) && (j <= end))
	{
		if (src[i] < src[j])
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}

	while (i <= mid)
	{
		des[k++] = src[i++];
	}

	while (j <= end)
	{
		des[k++] = src[j++];
	}
}

void MSort_rank(int* src, int* des, int head, int end, int max)
{
	if (head == end)
	{
		des[head] = src[head];
	}
	else
	{
		int mid = (head + end) / 2;
		int* space = (int*)malloc(sizeof(int) * max);

		if (space != NULL)
		{
			MSort_rank(src, space, head, mid, max);
			MSort_rank(src, space, mid + 1, end, max);
			Merge_rank(space, des, head, mid, end);
		}

		free(space);
	}
}

void MergeSort_rank(int *array, int len) // O(n*logn)
{
	MSort_rank(array, array, 0, len - 1, len);
	display(array, len);
}
