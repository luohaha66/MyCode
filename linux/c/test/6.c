#include <stdio.h>

float iseven(float n)
{
	if (n == 2.0)
		return 1 / 2.0;
	else
		{
			return iseven(n / 2.0) + 1 / n ;
		}
}

float uneven(float n)
{
	if (n == 1.0)
		return 1 / 1.0;
	else
		{
			return uneven(n - 2.0) + 1 / n ;
		}
}

int main()
{
	float m = 0.0;
	int   n = 0;
	printf("Please input number:\n");
	scanf("%f", &m);
	n = (int)m % 2;		
	if (n)
		{
			printf("%f\n", uneven(m));
		}
	else
		{
			printf("%f\n", iseven(m));
		}

}
