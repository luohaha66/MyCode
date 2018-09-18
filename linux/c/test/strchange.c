#include <stdio.h>
#include <string.h>

char* exchange(char* p)
{
	int i = 0;
	char a[20] = {0};
	strcpy(a, p);
	int len = strlen(p) - 1;
	for (i = 0; i < strlen(p); i++)
	{
		*(p + i) = a[len];
		len--;
	}
	return p;
}

int main()
{
	char a[20] = {0};
	char b[20] = {0};
	char c[20] = {0};
	printf("please input the first string:\n");
	scanf("%s", a);
	printf("please input the second string:\n");
	scanf("%s", b);
	strcpy(c, a);
	strcpy(a, b);
	strcpy(b, c);
	exchange(a);
	exchange(b);
	printf("the string after change is:\n");
	printf("%s \n", a);
	printf("%s \n", b);
}