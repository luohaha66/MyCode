#include <stdio.h>
#include <math.h>
#include <string.h>
  
#define M sizeof(unsigned int)*8 
void (*func)(unsigned long, int, char*);

int trans1(char *a,int d1)   /*将d1进制的num,转换为十进制数s*/  
{  
  int i = 0,num = 0,s = 0,P = 1;
  int len = strlen(a);
  char b[30] = {0};
  strcpy(b, a);
  for (i = len - 1, s = 0; i >= 0; i--, s++)
  {
  	*(a + i) = *(b + s);
  } 
  for (i = 0; i < len; i++)
    {  
        if(a[i] >= 'A' && a[i] <= 'F')   
        	num = a[i] - '0' - 7;  
        else if (a[i] >= 'a' && a[i] <= 'f') 
        	num = a[i] - '0' - 39;  
        else if (a[i] >= '0' && a[i]<='9') 
        	num = a[i] - '0';  
        else{  
               printf("Number is Error!\n");  
               break;  
            }  
        if(num < d1)  
        {  
            if(i == 0)
            	{
            		s = num;
            		s *= pow(d1, i);  
            	}
            else  
            {    
                s += num * pow(d1, i);  
            }  
         }  
        else  
        {  
            printf("Sacle is Invalid!\n");       /*不合规则(d1进制)的num*/  
            break;  
         }  
  
  	}
    return s;  
}  

void trans2(unsigned long n, int d, char *s) /* 将无符号整数n翻译成d（2<＝d<＝16）进制表示的字符串s */  
{  
    static char digits[] ="0123456789ABCDEF";  /* 十六进制数字的字符 */  
    char buf[M+1];  
    int j = 0, i = M;  
    s[0] = '\0';  
    if(d < 2 || d > 16)  
    {  
        s[0]='\0';  /* 不合理的进制，置s为空字符串 */  
        printf("Sacle is Invalid!\n");
        return ; 
    }  
    buf[i] = '\0';  
    do  
    {  
        buf[--i] = digits[n % d]; /*译出最低位，对应字符存入对应工作数组中*/  
        n /= d;  
    }while(n);  
  
    for(j = 0; (s[j] = buf[i]) != '\0'; j++, i++); /*将译出在工作数组中的字符串复制到s */   
}  

int main()
{
	char a[30];
	int i = 0;
	int j = 0;
	int n = 0;
	printf("Please inout the number you want to convert:\n");
	gets(a);
	printf("Please input your number's scale:\n");
	scanf("%d", &i);
	printf("Please input scale you want to convert:\n");
	scanf("%d", &j);
	n = trans1(a, i);
	printf("%d\n", n);
	func = trans2;
	func(n, j, a);
	printf("The Number After Convert is:\n");
	printf("%s\n", a);
}