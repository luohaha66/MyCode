#include "queue.h"

void qdisplay(queue* q, void(*print)(queue*, int))
{
	int t = q->front;
	while (t != q->rear)
	{
		print(q, t++);
	}
	printf("\n");
}

queue* create_queue()
{
	queue* q = (queue*)calloc(1, sizeof(struct queue));
	if (q == NULL)
		return NULL;
	q->front = 0;
	q->rear = 0;
	return q;
}

int queue_is_empty(queue* q)
{
	if (q == NULL)
		return -1;
	return ((q->front == q->rear) ? 1 : 0);
}

int queue_is_full(queue* q)
{
	if (q == NULL)
		return -1;
	if ((q->front - q->rear == 1) ||
		(q->rear - q->front == SIZE - 1))
		return 1;
	else
		return 0;
}

int insert_into_queue(queue* q, data_t data)
{
	if (q == NULL || queue_is_full(q))
		return -1;
	q->data[q->rear] = data;
	q->rear = (q->rear + 1) % SIZE;
	return 0;
}

data_t del_from_queue(queue* q)
{
	if (q == NULL || queue_is_empty(q))
		return -1;
	data_t c = NULL;
	c = q->data[q->front];
	q->front = (q->front + 1) % SIZE;
	return c;
}

void destory_queue(queue* q)
{
	free(q);
	q = NULL;
}

