#pragma once
#ifndef _CSTACK_H_
#define _CSTACK_H_

typedef struct NODE
{
	char data;
	struct NODE* prior;
}Node;

typedef struct STACK
{
	int length;
	Node* top;
	Node* bottom;
	Node* slider;
}Stack;

Stack* Stack_creat();

void Stack_push(Stack* stack,char c);

char Stack_pop(Stack* stack);

int Stack_length(Stack* stack);

char Stack_gettop(Stack* stack);

void Stack_destory(Stack* stack);

void Stack_clear(Stack* stack);

char Stack_get(Stack* stack);

#endif // !_STACK_H_
