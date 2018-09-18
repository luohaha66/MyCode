#include <stdio.h>
#include <string.h>

char *my_strstr(char *p, char *q)
{
		int flag = 0;
		int i    = 0;
		int j    = 0;
	  char *k  = NULL;
    for(i = 0; i < strlen(p); i++)
    {
        if(*( p + i) == *(q + 0))
        {
            for(j = 0; '\0' != *(q + j); j++)
            {
                if(*(p + i + j) != *(q + j))
                {
                    flag = 1;
                    break;
                }
            }
            if(0 == flag)
            {
              k = (p + i);
            }
        }
    }
    strcpy(p, k);
    return p;
}

int main()
{
	char a[30];
	char b[10];
	printf("PLesase input some data:\n");
	gets(a);
	printf("Please input the string you want to find:\n");
	gets(b);
	printf("%s\n", my_strstr(a, b));
}