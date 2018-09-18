#pragma once
#ifndef _LSTACK_H_
#define _LSTACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef int data_st;
typedef struct stack {
	data_st data;
	struct stack* next;
}lstack;

void sdisplay(lstack* l, void(*print)(lstack*));
lstack* create_lstack();
int lstack_is_empty(lstack* l);
int get_ele_number(lstack* l);
int lstack_push(lstack* l, data_st data);
data_st lsatck_pop(lstack* l);
void clear_lstack(lstack* l);
void destory_lstack(lstack* l);

#endif // !_LSTACK_H_
