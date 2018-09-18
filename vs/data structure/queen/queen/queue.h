#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef int data_t;
typedef struct queue {
	data_t data[SIZE];
	int front, rear;
}queue;

void qdisplay(queue* q, void(*print)(queue*, int));
queue* create_queue();
int queue_is_empty(queue* q);
int queue_is_full(queue* q);
int insert_into_queue(queue* q, data_t data);
data_t del_from_queue(queue* q);
void destory_queue(queue* q);

#endif // !_QUEEN_H_
