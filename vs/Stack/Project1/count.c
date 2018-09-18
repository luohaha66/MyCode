#include<stdio.h>
#include<malloc.h>
#include"Count.h"


int isnumber(char c)
{
	return ('0' <= c) && (c <= '9');
}

int isoperator(char c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int value(char c)
{
	return (c - '0');
}

int express(int left, int right, char op)
{
	int ret = 0;

	switch (op)
	{
	case '+':
		ret = left + right;
		break;
	case '-':
		ret = left - right;
		break;
	case '*':
		ret = left * right;
		break;
	case '/':
		ret = left / right;
		break;
	default:
		break;
	}

	return ret;
}

/*int compute(const char* exp)
{
	Dstack* dstack = Dstack_creat();
	int ret = 0;
	int i = 0;

	while (exp[i] != '\0')
	{
		if (isnumber(exp[i]))
		{
			Dstack_push(dstack, value(exp[i]));
		}
		else if (isoperator(exp[i]))
		{
			int right = Dstack_pop(dstack);
			int left = Dstack_pop(dstack);
			int result = express(left, right, exp[i]);

			Dstack_push(dstack, result);
		}
		else
		{
			printf("Invalid expression!");
			break;
		}

		i++;
	}

	if ((Dstack_length(dstack) == 1) && (exp[i] == '\0'))
	{
		ret = Dstack_pop(dstack);
	}
	else
	{
		printf("Invalid expression!");
	}

	Dstack_destory(dstack);

	return ret;
}*/


