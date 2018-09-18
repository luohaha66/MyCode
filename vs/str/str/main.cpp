#include <stdio.h>
#include "str.h"

int main()
{
	char a[20] = "abcdef";
	char b[10];
	printf("%s \n", my_strcpy(a, b));
	return 0;
}