#include <stdio.h>
#include <string.h>

char *delspace(char *p)
{
	int i = 0;
	int j = 0;
	for(i = 0; i < strlen(p); i++)
	{
		if (*(p + i) == ' ')
			{
				for (j = i; j < strlen(p); j++)
				{
					*(p + j) = *(p + j + 1);
				}
			}
	}
	return p;
}

int main()
{
	char a[30];
	printf("Please input some data:\n");
	gets(a);
	printf("After del the space is:\n");
	printf("%s\n", delspace(a));
}
