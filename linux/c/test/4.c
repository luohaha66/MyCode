#include <stdio.h>
#include <string.h>
#include <malloc.h>

int i = 0;

void display(int *p)
{
	int j = 0;
	for(j = 0; j < i; j++)
	{
		printf("%d", *(p + j));
	}
	printf("\n");
}

void chartoint(char *p, int *q)
{
	for (i = 0; i < strlen(p); i++)
	{
		*(q + i) = (int)(*(p + i) - '0');
	}
}

int *changepos(int *a, int m)
{
	int j = 0;
	int n = 0;
	int *p = (int*)malloc(sizeof(int) * 30);
	for (j = m; j < i; j++)
	{
		*(p + n) = *(a + j);
		n++;
	}
	for (j = 0; j < m; j++)
	{
		*(p + n) = *(a + j);
		n++;
	}
  for(j = 0; j < i; j++)
  {
  	*(a + j) = *(p + j);
  }
  free(p);
  p = NULL;
	return a;
} 

int main()
{
	int  a[30] = {0};
	char b[30] = {0};
	int m = 0;
	printf("PLease input some number:\n");
	gets(b);
	printf("the number you want to exchange position is:\n");
	scanf("%d", &m);
	chartoint(b ,a);
	changepos(a, m);
	printf("the number after change position is:\n");
	display(a);
}
