#include "search.h"

int reduce_by_half_search_method(int* a, int len, int i) /*must be rank first*/
{
	if (a == NULL || len < 0)
		return -1;
	int low, high, mid;
	low = 0;
	high = len - 1;
	mid = (low + high) / 2;
	while (low <= high)
	{
		if (a[mid] == i)
			return mid;
		if (a[mid] > i)
		{
			high = mid - 1;
			mid = (low + high) / 2;
		}
		if (a[mid] < i)
		{
			low = mid + 1;
			mid = (low + high) / 2;
		}
	}
	return -1;
}

void my_display(int* a, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void swap(int* a, int i, int j)
{
	int temp = 0;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void bubbling_rank(int* a, int len) /*bubbling rank methond, time = n * n , stable*/
{
	int i = 0;
	int j = 0;
	int flag = 1;
	for (i = 0; i < len && flag; i++)
	{
		flag = 0;
		for (j = len - i - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(a, j - 1, j);
				flag = 1;
			}
		}
	}
}

void compare_rank(int* a, int len) /*compare rank methond, time = n * n */
{
	int i = 0;
	int j = 0;
	for (i = 1; i < len; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
				swap(a, j, j + 1);
		}
	}
}

void insert_rank(int* a, int len) /*insert rank methond, time = n * n, stable */
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 1; i < len; i++)
	{
		k = a[i];
		j = i - 1;
		while (k < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = k;
	}
}

void insert_rank_1(int* a, int len) /*shell rank method, time = n*logn,unstable*/
{
	int i = 0;
	int j = 0;
	int k = 0;
	int gap = len;
	do
	{
		gap = gap / 3 + 1;
		for (i = gap; i < len; i += gap)
		{
			k = a[i];
			j = i - gap;
			while (k < a[j])
			{
				a[j + gap] = a[j];
				j -= gap;
			}
			a[j + gap] = k;
		}
	} while (gap > 1);
}

int find_position(int* a, int head, int end)
{
	int p = a[0];
	while (head < end)
	{
		while ((head < end) && (a[end] > p))
			end--;
		swap(a, head, end);
		while ((head < end) && (a[head] < p))
			head++;
		swap(a, head, end);
	}
	return head;
}

void repeat_find(int*a, int head, int end)
{
	if (head < end)
	{
		int position = find_position(a, head, end);
		repeat_find(a, head, position - 1);
		repeat_find(a, position + 1, end);
	}
}

void quickly_rank(int* a, int head, int end) /*quickly rank method,time: n*logn,unstable*/
{
	repeat_find(a, head, end - 1);
}

void selection_rank(int*a, int len) /*selection rank method, time: n * n, stable*/
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < len; i++)
	{
		k = i;
		for (j = i + 1; j < len; j++)
		{
			if (a[k] > a[j])
				k = j;
		}
		swap(a, i, k);
	}
}

void copy(int* a, int* b, int head, int mid, int end)
{
	int i = head;
	int j = mid + 1;
	int k = head;
	while ((i <= mid) && (j <= end))
	{
		if (a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i <= mid)
		b[k++] = a[i++];
	while (j <= end)
		b[k++] = a[j++];
}

void mergesort(int* a, int * b, int head, int end, int max)
{
	if (head == end)
		b[head] = a[head];
	else
	{
		int mid = (head + end) / 2;
		int* space = (int*)calloc(1, max * 4);
		if (space != NULL)
		{
			mergesort(a, space, head, mid, max);
			mergesort(a, space, mid + 1, end, max);
			copy(space, b, head, mid, end);
		}
		free(space);
		space = NULL;
	}
}

void merge_rank(int* a, int len) /*guibing rank method, time:n*logn, stable*/
{
	mergesort(a, a , 0, len - 1, len);
}