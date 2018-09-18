#include<stdio.h>
#include"rank.h"

int main(int argc, char* argv[])
{
	int array[] = { 45,52,63,22,5,9 };
	int len = sizeof(array) / sizeof(*array);
	order_rank(array, len);
	bubbling_rank(array, len);
	shell_insert_rank(array, len);
	quick_rank(array, 0, len);
	MergeSort_rank(array, len);
	return 0;
}