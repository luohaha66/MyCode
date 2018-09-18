#include "lqueue.h"

void displaylq(point* lq, void(*print)(lqueue*))
{
	if (lq == NULL)
		return;
	lqueue* q = lq->front->next;
	while (q)
	{
		print(q);
		q = q->next;
	}
	printf("\n");
}

point* create_lqueue()
{
	point* lq = (point*)calloc(1, sizeof(struct point));
	if (lq == NULL)
		return NULL;
	lq->front = (lqueue*)calloc(1, sizeof(struct lqueue));
	if (lq->front == NULL)
		return NULL;
	lq->rear = lq->front;
	lq->front->next = NULL;
	lq->rear->next = NULL;
	return lq;
}

int lqueue_is_empty(point* lq)
{
	if (lq == NULL)
		return -1;
	return ((lq->front == lq->rear) ? 1 : 0);
}

int get_lqele_number(point* lq)
{
	if (lq == NULL)
		return -1;
	int i = 0;
	lqueue* p = lq->front->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

int insert_into_lqueue(point* lq, data_qt data)
{
	if (lq == NULL)
		return -1;
	lqueue* p = (lqueue*)calloc(1, sizeof(struct lqueue));
	if (p == NULL)
		return -1;
	p->data = data;
	p->next = NULL;
	lq->rear->next = p;
	lq->rear = p;
	return 0;
}

data_qt del_from_lqueue(point* lq)
{
	if (lq == NULL || lqueue_is_empty(lq))
		return -1;
	data_qt c = NULL;
	lqueue* q = lq->front->next;
	c = q->data;
	if (q->next == NULL)
	{
		lq->front->next = NULL;
		lq->rear = lq->front;
		lq->rear->next = NULL;
		free(q);
		q = NULL;
	}
	else
	{
		lq->front->next = q->next;
		free(q);
		q = NULL;
	}
	return c;
}

void clear_lqueue(point* lq)
{
	if (lq == NULL || lqueue_is_empty(lq))
		return;
	lqueue* q = lq->front;
	lqueue* p = lq->front->next;
	while (q)
	{
		q = p->next;
		free(p);
		p = q;
	}
}

void destory_lqueue(point* lq)
{
	clear_lqueue(lq);
	free(lq);
	lq = NULL;
}