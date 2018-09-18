#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Search.h"
 
int main(int argc, char* argv[])
{	
	/*int j = 0;
	srand((unsigned int)time(NULL));
	j = rand() % 100;
	printf("the data youwant to search is: %d \n", j);
	search_data(0, 14, j);*/
	int a[] = { 12,14,152,153,14,153,12,152,153,153,153,12};
	int len = sizeof(a) / sizeof(*a);
	search_not_pai_2(a, len);
}
