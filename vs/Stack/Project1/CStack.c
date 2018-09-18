#include<stdio.h>
#include<malloc.h>
#include"Cstack.h"

Stack* Stack_creat()
{
	Stack *ret= (Stack*)malloc(sizeof(Stack));
	if (ret!= NULL)
	{
		ret->length = 0;
		ret->bottom = NULL;
		ret->top = NULL;
	    Node* p = (Node*)malloc(sizeof(Node));
		ret->top = p;
		ret->bottom = p;
		ret->slider=ret->bottom;
		ret->bottom->prior = NULL;
		ret->top->prior = NULL;
		ret->slider->prior = NULL;
	}
	return ret;
}

void Stack_push(Stack* stack,char c)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if ((stack != NULL) && (node != NULL))
	{
		node->data = c;
		node->prior = stack->top;
		stack->top = node;
	}
	stack->length++;
}

char Stack_pop(Stack* stack)
{
	char c;
	Node* p = NULL;
	if ((stack != NULL) && (stack->length > 0))
	{
		p = stack->top;
		stack->top = p->prior;
	}
	c = p->data;
	free(p);
	p = NULL;
	stack->length--;
	return c;
}

int Stack_length(Stack* stack)
{
	int i = 0;
	if (stack != NULL)
	{
	 i = stack->length;
	}
	return i;
}

char Stack_gettop(Stack* stack)
{
	char c;
	if (stack != NULL)
	{
	 c = stack->top->data;
	}
	return c;
}

void Stack_destory(Stack* stack)
{
	Stack_clear(stack);
	free(stack);
	stack = NULL;
}

void Stack_clear(Stack* stack)
{
	if (stack != NULL)
	{
		while (Stack_length(stack)>0)
		{
			Stack_pop(stack);
		}
	}
}

char Stack_get(Stack* stack)
{
	char c;
	stack->slider= stack->top;
	if ((stack != NULL) && (Stack_length(stack)) > 0)
	{
		while (stack->slider!= stack->bottom)
		{
			c = stack->slider->data;
			printf("%c\n",c);
			stack->slider =stack->slider->prior;
		}
	}
	return c;
}
