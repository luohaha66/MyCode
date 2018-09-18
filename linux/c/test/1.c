#include <stdio.h>
#include <string.h>


char *delstr(char *p)
{
	char *m = p;
	int   i = 0;
	int   j = 0;
	int   k = 0;
	int   a = 0;
	int   f = 0;
	int len = strlen(p);
	for(i = 0; i < strlen(p); i++)
	{
		for (j = i + 1; j < strlen(p); j++)
		{
			if (*(p + i) == *(m + j))
				{
					f = 1;
					for (k = j; k < strlen(p); k++)
					{
						*(p + k) = * (p + k + 1);
					}
					for(a = i; a < strlen(p); a++)
					{
						*(p + a) = *(p + a + 1);
					}
				}
		} 
		if (f)
			{
				i = -1;
				f = 0;
			}
	}
	return p;
}

int main()
{
	char a[30];
	printf("Please input some data:\n");
	scanf("%s", a);
	printf("The string before del is:\n");
	printf("%s\n", a);
	printf("The string after del is:\n");
	printf("%s\n", delstr(a));
}
