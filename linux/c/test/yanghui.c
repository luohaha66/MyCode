#include <stdio.h>
#define LEN 13

int main()
{
	int a[LEN][LEN] = {{1}, {1,1}};
	int i = 2;
	int j = 0;
	for (i = 2; i < LEN; i++)
	{
		a[i][j] = 1;
		for (j = 1; j < i; j++)
		{
			a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
		a[i][j] = 1;
		j = 0;
	}
	
	for (i = 0; i < LEN; i++)
	{
		for (j = 0; j < LEN - i - 1; j++)
		printf ("  ");
		for (j = 0; j <= i;j++)
		printf (" %3d ",a[i][j]);
		printf ("\n");
	}
	return 0;
}