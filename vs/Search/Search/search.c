#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Search.h"

void display_slist(Slist* list)
{
	int i = 0;
	int j = 0;
	printf("the list data is:\n");
	for (i = 0; i < Slist_length(list); i++)
	{
		j = Slist_get(list, i);
		printf(" %d ", j);
	}
	printf("\n");
}

void search_data(int head,int end,int j)
{
	Slist* list = Slist_creat(MAX);
	int i = 0;
	int k = 0;
	int ret = Slist_capacity(list);
	srand((unsigned int)time(NULL));
	for (i = 0; i < Slist_capacity(list); i++)
	{
		k = rand() % 100;
		Slist_insert(list, k, i);
	}
	display_slist(list);
	maopao_rank(list);
	//ret = binary_rank(list, head, end, j);
	ret=interpolation_search(list, head, end, j);
	if (ret > 0)
	{
		printf("search succes:\n");
		printf("the index is %d \n", ret);
		Slist_delete(list, ret);
		display_slist(list);
	}
	else
	{
		printf("search failed\n");
	}
	Slist_destory(list);
}

void swap(int* a, int i, int j)
{
	int temp = 0;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void maopao_rank(Slist* list)
{
	int i = 0;
	int j = 0;
	int ret = 0;
	int k = 1;
	int a[15] = {0};
	for (i = 0; i < Slist_capacity(list); i++)
	{
		a[i] = Slist_get(list, i);
	}
	for (i = 0; i < Slist_capacity(list); i++)
	{
		Slist_delete(list, i);
	}
	for (i = 0;i < 15 && k; i++)
	{
		k = 0;
		for (j = 14; j > 0; j--)
		{
			if (a[j-1]> a[j])
			{
				k = 1;
				swap(a, j - 1, j);
			}
		}
	}
	for (i = 0; i < 15; i++)
	{
		Slist_insert(list,a[i],i);
	}
	printf("after rank \n");
	display_slist(list);
}

int binary_rank(Slist* list, int head, int end,int j)
{
	/*int mid=0;  //无栈空间的大量使用，更高效
	int ret = 0;
	while (head < end)
	{
		mid = (head + end) / 2;
		if (Slist_get(list, mid) == j)
		{
			ret = mid;
			break;
		}
		else if (Slist_get(list, mid) < j)
		{
			head = mid + 1;
		}
		else if (Slist_get(list, mid) > j)
		{
			end = mid - 1;
		}
	}
	return ret;*/

	int ret = -1;

	if (head <= end)
	{
		int mid = (head + end) / 2;

		if (Slist_get(list,mid) == j)
		{
			ret = mid;
		}
		else if (j <Slist_get(list, mid))
		{
			ret = binary_rank(list, head, mid - 1,j);
		}
		else if (j > Slist_get(list, mid))
		{
			ret = binary_rank(list, mid + 1, end, j);
		}
	}

	return ret;
}

int interpolation_search(Slist* list, int head, int end, int j)
{
	int ret = -1;

	while ((head <= end) && (Slist_get(list,head) <= j) && (j <= Slist_get(list,end)))
	{
		float fx = 1.0f * (j - Slist_get(list, head)) / (Slist_get(list, end) - Slist_get(list, head));
		int mid = head + fx * (end - head);

		if (Slist_get(list, mid) == j)
		{
			ret = mid;
			break;
		}
		else if (j < Slist_get(list, mid))
		{
			end = mid - 1;
		}
		else if (j > Slist_get(list, mid))
		{
			head = mid + 1;
		}
	}

	return ret;
}

//查找一个数组中不成对出现的一个数
void search_not_pair(int* a,int len)
{
	int i = 0;
	int result = 0;
	if ((a != NULL) && (len > 2))
	{
		for (i = 0; i < len; i++)
		{
			result ^= a[i];
		}
	}
	printf("the number not pair is %d \n", result);
}

//查找一个数组中不成对出现的两个数
void search_not_pai_2(int* a, int len)
{
	int i = 0;
	int result = 0;
	int index = 0;
	int j = 0;
	int num1 = 0;
	int num2 = 0;
	if ((a != NULL) && (len > 2))
	{
		for (i = 0; i < len; i++)
		{
			result ^= a[i];
		}
	}
	index = find_firstbit_is_1(result, len);
	for (i = 0; i < len; i++)
	{
		if (is_Bit_1(a[i], index))
		{
			num1 ^= a[i];
		}
		else
		{
			num2 ^= a[i];
		}
	}
	printf("the first number not pair is %d \n", num1);
	printf("the second number not pair is %d \n", num2);
}

int find_firstbit_is_1(int result,int len)
{
	int index_bit_1 = 0;
	while ((result & 1 == 0) && (index_bit_1 < len * sizeof(int)))
	{
		result >>= 1;
		index_bit_1++;
	}
	return index_bit_1;
}

int is_Bit_1(int num,int index)
{
	num ^= index;
	return (num & 1);
}