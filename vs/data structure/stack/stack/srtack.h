#pragma once
#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>

#define SIZE 20

typedef int data_t;
typedef struct stack
{
	data_t data[SIZE];
	int top;
}stack;

void display(stack* s, void(*print)(stack*, int));
stack* create_stack();
int stack_is_empty(stack* s);
int stack_is_full(stack* s);
int stack_push(stack* s, data_t data);
data_t stack_pop(stack* s);
int get_ele_number(stack* s);
void destory_stack(stack* s);

#endif // !_STACK_H_
