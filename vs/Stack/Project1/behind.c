#include <stdio.h>
#include<string.h>
#include"Cstack.h"
#include"Behind.h"

int isNumber(char c)
{
	return ('0' <= c) && (c <= '9');
}

int isOperator(char c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int isLeft(char c)
{
	return (c == '(');
}

int isRight(char c)
{
	return (c == ')');
}

int priority(char c)
{
	int ret = 0;

	if ((c == '+') || (c == '-'))
	{
		ret = 1;
	}

	if ((c == '*') || (c == '/'))
	{
		ret = 2;
	}

	return ret;
}

void output(char c)
{
	if (c != '\0')
	{
		printf("%c", c);
    }
}

void transform(const char* exp)
{
	int i = 0;
	Stack* cstack = Stack_creat();
	while (exp[i] != '\0')
	{
		if (isNumber(exp[i]))
		{
			output(exp[i]);
		}
		else if (isOperator(exp[i]))
		{
			while (priority(exp[i]) <= priority(Stack_gettop(cstack)))
			{
				output(Stack_pop(cstack));
			}

			Stack_push(cstack, exp[i]);
		}
		else if (isLeft(exp[i]))
		{
		Stack_push(cstack, exp[i]);
		}
		else if (isRight(exp[i]))
		{
			char c = '\0';

			while (!isLeft(Stack_gettop(cstack)))
			{
				output( Stack_pop(cstack));
	
			}

			Stack_pop(cstack);
		}
		else
		{
			printf("Invalid expression!");
			break;
		}

		i++;
	}

	while ((Stack_length(cstack) > 0) && (exp[i] == '\0'))
	{
		output( Stack_pop(cstack));
	}
	Stack_destory(cstack);
}


