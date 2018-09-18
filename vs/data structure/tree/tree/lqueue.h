#pragma once
#ifndef _LQUEUE_H_
#define _LQUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef tree* data_qt;
typedef struct lqueue {
	data_qt data;
	struct lqueue* next;
}lqueue;

typedef struct point {
	lqueue* front;
	lqueue* rear;
}point;

void displaylq(point* lq, void(*print)(lqueue*));
point* create_lqueue();
int lqueue_is_empty(point* lq);
int get_lqele_number(point* lq);
int insert_into_lqueue(point* lq, data_qt data);
data_qt del_from_lqueue(point* lq);
void clear_lqueue(point* lq);
void destory_lqueue(point* lq);
#endif // !_LQUEUE_H_

