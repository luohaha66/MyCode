#include <stdio.h>
#include <string.h>

void display(int *p, int i)
{
	int j = 0;
	for(j = 0; j < i; j++)
	{
		printf("%d", *(p + j));
	}
	printf("\n");
}

void calculate(int *a, int n, int *ev, int *od)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] % 2)
			{
				*od = *od + a[i]; 
			}
		else
			{
				*ev = *ev + a[i];
			}
	}
}

int main()
{
	int a[30];
	int i  = 0;
	int n  = 0;
	int ev = 0;
	int od = 0;
	printf("Please input the numbers of number:\n");
	scanf("%d", &n);
	printf("Please input all of the number:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	calculate(a, n, &ev, &od);
	printf("The even number's sum is:\n");
	printf("%d\n", ev);
	printf("The odd number's sum is:\n");
	printf("%d\n", od);
}