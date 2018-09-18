#include <stdio.h>
#include <string.h>

char *str(char *p, char *q)
{
	int i = 0;
	int s = strlen(p);
	while(*(p + s + i) = *(q + (i++)));//不同的编译器对这句话的执行顺序可能不同，最好加上0作为保证
	*p = '\0';
	return p;
}

int main()
{
	char a[10] = "hello";
	char b[10] = " world";
	printf("%s\n", str(a, b));
}