#include <stdio.h>
#include <string.h>

char *change(char *p)
{
	int i = 0;
	int j = 0;
	int z = 0;
	int k = 0;
	char b[30] = {0};
	int len = strlen(p) - 1;
	for(i = len; i >= 0; i--)
	{
		if (p[i] == ' ')
			{
				k = len - strlen(b);
				j = i + 1;
				for(; j <= k; j++)
				{
					b[z++] = p[j]; 
				}
				b[z++] = ',';
				b[z++]   = ' ';
			}
		if (i == 0)
			{
				k = len - strlen(b);
				for (j = 0; j <= k; j++)
				{
					b[z++] = p[j];
				}
			}
	}
	strcpy(p, b);
	return p;
	
}

int main()
{
	char a[30] = {0};
	printf("please input data(Note: PinYin):\n");
	gets(a);
	printf("the PinYin after change is: \n");
	change(a);
	printf("%s\n", a);
}