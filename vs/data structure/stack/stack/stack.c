#include "srtack.h"

void display(stack* s, void(*print)(stack*, int))
{
	if ((s == NULL) || (stack_is_empty(s)))
		return -1;
	int i = 0;
	for (i = 0; i < s->top; i++)
		print(s, i);
	printf("\n");
}

stack* create_stack()
{
	stack* s = (stack*)calloc(1, sizeof(struct stack));
	if (s == NULL)
		return NULL;
	s->top = 0;
	return s;
}

int stack_is_empty(stack* s)
{ 
	if (s == NULL)
		return -1;
	return ((s->top == 0) ? 1 : 0);
}

int stack_is_full(stack* s)
{
	if (s == NULL)
		return -1;
	return ((s->top == SIZE - 1) ? 1 : 0);
}

int stack_push(stack* s, data_t data)
{
	if ((s == NULL) || (stack_is_full(s)))
		return -1;
	s->data[s->top] = data;
	s->top++;
	return 0;
}

data_t stack_pop(stack* s)
{
	if ((s == NULL) || (stack_is_empty(s)))
		return -1;
	data_t c = s->data[s->top];
	s->top--;
	return c;
}

int get_ele_number(stack* s)
{
	if ((s == NULL) || (stack_is_empty(s)))
		return -1;
	return s->top + 1;
}

void destory_stack(stack* s)
{
	if (s == NULL)
		return;
	free(s);
	s = NULL;
}