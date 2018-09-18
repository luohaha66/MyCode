#include <stdio.h>
#include <math.h>
#include "str.h"

int my_strlen(char* s)
{
	int i = 0;
	while (*s++)
		i++;
	return i;
}

char* my_strcpy(char* s, char* p)
{
	int i = 0;
	while (*(p + i) = *(s + (i++)));
	return p;
}

int my_strcmp(char* s, char* p)
{
	int i = 0;
	int flag = 0;
	int slen = my_strlen(s);
	int plen = my_strlen(p);
	int len  = 0;
	if (slen > plen)
		len = slen;
	else
		len = plen;
	for (i = 0; i < len; i++)
	{
		if (*(s + i) > *(p + i))
		{
			flag = 1;
			break;
		}
		if (*(s + i) < *(p + i))
		{
			flag = -1;
			break;
		}
		else if (*(s + i) == '\0' && *(p + i) == '\0')
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

char* my_strcat(char* s, char* p)
{
	int i = 0;
	int len = my_strlen(s);
	while (*(s + len + i) = *(p + (i++)));//不同的编译器对这句话的执行顺序可能不同，最好加上0作为保证
	*s = '\0';
	return s;
}

char* my_strdel(char* s, char* q) //删除子串函数
{
	int flag = 0;
	int m = my_strlen(s);
	int n = my_strlen(q);
	int j = 0;
	int k = 0;
	int i = 0;
    for(i = 0; i < m; i++)
    {
        if(*(s + i) == *(q + j))
        {
            for(j = 0; '\0' != *(q + j); j++)
            {
                if(*(s + j + i) != *(q + j))
                {
                    flag = 1;
                    break;
                }
            }
            if(0 == flag)
            {
                for(k = 0; k < n; k++)
                {
                    for(j = i; j < m; j++)
                    {
                        *(s + j) = *(s + j + 1);
                    }
                }
            }
            flag = 0;
        }
    }
    return s;
}

char* my_strins(char* s, char* t, int m) //字符串插入函数
{
	int i = my_strlen(t);
	int n = my_strlen(s);
	int j = 0;
	char* q  = (char*)malloc(50);
	while(*(q + j) = *(s + m + j++));
	*(s + m) = '\0';
	my_strcat(s, t);
	my_strcat(s, q);
	free(q);
	q = NULL;
	return s;
}

int continumax(char *outputstr,char *inputstr) //找出最长数字串
{
	int i = 0;
	int j = 0;
	int k = 0;
	int m = 0;
	int len = strlen(inputstr);
	int a[20] = {0};
	for (i = 0; i < len; i++)
	{
		  while(*(inputstr + i ) >= '0' && *(inputstr + i) <= '9')
			{
				j++;
				i++;
			} 
			if (j > k)
				{
					k = j;
					m = i - k;
				}
			j = 0;
	}
	j = 0;
	for (i = m; i < m + k; i++)
	{
		*(outputstr + j++) = *(inputstr + i);
	}
	*(outputstr + j) = '\0';
	return k;
}

long my_atol(const char* nptr) //字符串转数字
{
	long n = 0;
	char sign = '0';
	char c = '0';
	c = *(nptr++);
	sign = c;
	if (c == '+'|| c == '-')
		c = *(nptr++);
	while (c >= '0' && c <= '9')
	{
		n = 10 * n + (c - '0');
		c = *(nptr++);
	}
	if (sign == '-')
		return -n;
	else
		return n;
}

char* exchange(char* p)  //字符串倒序
{
	int i = 0;
	char a[20] = {0};
	strcpy(a, p);
	int len = strlen(p) - 1;
	for (i = 0; i < strlen(p); i++)
	{
		*(p + i) = a[len];
		len--;
	}
	return p;
}

char *delstr(char *p)  //删除字符串中重复的字符
{
	char *m = p;
	int   i = 0;
	int   j = 0;
	int   k = 0;
	int   a = 0;
	int   f = 0;
	int len = strlen(p);
	for(i = 0; i < strlen(p); i++)
	{
		for (j = i + 1; j < strlen(p); j++)
		{
			if (*(p + i) == *(m + j))
				{
					f = 1;
					for (k = j; k < strlen(p); k++)
					{
						*(p + k) = * (p + k + 1);
					}
					for(a = i; a < strlen(p); a++)
					{
						*(p + a) = *(p + a + 1);
					}
				}
		} 
		if (f)
			{
				i = -1;
				f = 0;
			}
	}
	return p;
}

char *my_strstr(char *p, char *q) //字串查找函数
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

int *changepos(int *a, int m) //字符串前后对调函数
{
	int j = 0;
	int n = 0;
	int *p = (int*)malloc(sizeof(int) * 30);
	for (j = m; j < i; j++) //i = strlen(a)
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

char* my_itoa(int m,char* s) //整数转为字符串
{
	int i = 0;
	int j = 0;
	char b[20] = {0};
	while (m)
	{
		b[i++] = m % 10 + '0';
		m /= 10;
	}
	i--;
	while (i >= 0)
	{
		s[j++] = b[i--];
	}
	s[j] = '\0';
	return s;
}

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