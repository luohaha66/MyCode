#include <stdio.h>
#include <string.h>

int my_strcmp(char a, char b)
{
	if (a == b)
		return 1;
  else
  	return 0;
}

int my_strlen(char* a)
{
	int i = 0;
	int len = 0;
	while(a[i++]);
	len = i - 1;
	return len;
}

int main()
{
	char a[100];
	char b[20];
	int i = 0;
	int j = 0;
	int p = 0;
	printf("please input some data:\n");
	scanf ("%s", a);
	printf("please input the string you want to find:\n");
	scanf ("%s", b);
			for(; j < my_strlen(a); j++)
			{
			if (my_strcmp(b[i], a[j]))
				{
					while (b[i])
					{
						j++;
						i++;
						if (my_strcmp(b[i], a[j]))
							{
							}
							else
								break;
					}
					if (i = my_strlen(b))
						{
							p = j - my_strlen(b);
							printf ("find string at position %d, find string is %s \n", p, b);
							i = 0;
						}
						j--;
				}
				
			 else if (a[j] == '\0' && p == 0)
					{
						printf ("can't find string in the data\n");
					}
			}
	return 0;
}