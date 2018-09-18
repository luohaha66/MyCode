#include <stdio.h>
#include <string.h>

void my_div(float a, float b)
{
	if ( b > -0.000001 && b < 0.000001 )
		{
			printf ("the divisor can't be 0\n");
			return;
		}
		else 
		{
			float c = a / b;
			printf ("the result is %f\n", c);
		}
}

int main()
{
my_div(5,0.0);
	return 0;
}