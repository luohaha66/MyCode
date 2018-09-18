#include<stdio.h>
#include<malloc.h>
#include"Queen.h"

Queen* Queen_creat()
{
	 Queen* ret= (Queen*)malloc(sizeof(Queen));
	if (ret != NULL)
	{
		ret->front = 0;
		ret->front = NULL;
		ret->rear = NULL;
		ret->length = 0;
		Qnode* p = (Qnode*)malloc(sizeof(Qnode));
		ret->front = p;
		ret->rear = p;
		ret->front->prior = NULL;
		ret->rear->prior = NULL;
	}
	return ret;
}

void Queen_insert(Queen* queen, int c)
{
	Qnode* node = (Qnode*)malloc(sizeof(Qnode));
	if ((queen != NULL) && (node != NULL))
	{
		node->data = c;
		queen->rear->prior = node;
		queen->rear = node;
		node->prior = NULL;
	}
	queen->length++;
}

int Queen_del(Queen* queen)
{
	int c;
	Qnode* p = NULL;
	if ((queen != NULL) && (queen->length > 0))
	{
		p = queen->front->prior;
	}
	if (queen->rear == p)
	{
		queen->rear = queen->front;
	}
	else
	{
		queen->front ->prior= p->prior;
	}
	c = p->data;
	free(p);
	p = NULL;
	queen->length--;
	return c;
}

int Queen_length(Queen* queen)
{
	int i = 0;
	if (queen != NULL)
	{
		i = queen->length;
	}
	return i;
}


void Queen_destory(Queen* queen)
{
	Queen_clear(queen);
	free(queen);
	queen = NULL;
}

void Queen_clear(Queen* queen)
{
	if (queen != NULL)
	{
		while (Queen_length(queen)>0)
		{
			Queen_del(queen);
		}
	}
}

