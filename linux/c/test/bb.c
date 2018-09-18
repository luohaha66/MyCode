#include <stdio.h>
#include <malloc.h>
#include <string.h>

int len;

int* rank(int* a)
{
	int i = 0; 
	while(i < len)  
	{  
		if(*(a + i) == (i + 1))  
			i++;  
		else  
			{  
				int pos = *(a + i);  
				int temp = a[pos - 1];  
				a[pos - 1] = pos;  
				a[i] = temp;  
			}  
	}  
	return a;
}

int main()
{

}
