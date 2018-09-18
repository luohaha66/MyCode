#include <stdio.h>

void data(int* a)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
}

void display(int* a)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%5d", a[i]);
	}
	printf ("\n");
}

void swap(int* a, int i, int j)
{
	int t = 0;
	t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void rank(int* a)
{
	int i = 0;
	int j = 0;
	for(i = 0; i < 10; i++)
	{
		for(j = 9; j > i; j--)
		{
			if( a[j] < a[i])
				{
					swap(a, i, j);
				}
		}
	}
}

int main()
{
	int a[10];
	printf("please input 10 number:\n");
	data(a);
	printf("the number you input is:\n");
	display(a);
	printf("the number after ranking is:\n");
	rank(a);
	display(a);
	return 0;
}