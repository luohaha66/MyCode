#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include "Qlist.h"


Qlist* Qlist_creat()
{
	 Qlist *ret = (Qlist*)malloc(sizeof(Qlist));
	if (ret != NULL)
	{
		ret->length = 0   ;
		ret->next = ret;
		ret->slider = NULL;
		ret->prior = ret;
		ret->data = 0;
	}
	return ret;
}

void Qlist_destory(Qlist* list)
{
	Qlist_clear(list);
	free(list);
	list = NULL;
}

void Qlist_clear(Qlist* list)
{
	while (Qlist_length(list) > 0)
	{
		Qlist_delete(list, Qlist_length(list) - 1);
	}
	if (Qlist_length(list)== 0)
	{
		list->length = 0;
		list->next = list;
		list->slider = NULL;
		list->prior = list;
	}
}

int Qlist_length(Qlist* list)
{
	int ret = -1;
	if (list != NULL)
	{
		ret = list->length;
	}
	return ret;
}

int Qlist_insert(Qlist* list, int node, int pos)
{
	int ret = (list != NULL) && (pos >= 0);
	Qlist* last = NULL;
	Qlist* q = NULL;
	Qlist* first = list->next;
		if (Qlist_length(list) > 0)
	{
		last = Qlist_get(list, (list->length - 1));
	}
	Qlist* p = list;
	int i = 0;
	if (ret)
	{
		for (i = 1; i < pos && (p->next != NULL); i++)
			p = p->next;
	}
	q = p->next;
	Qlist *s = (Qlist*)malloc(sizeof(Qlist));
	if (list->length == 0)
	{
		list->prior = list;
		list->next = s;
		s->next = s;
		s->prior = s;
        list->slider = s;
	}
    if ((Qlist_length(list)==1))
	{
		q->next = s;
		q->prior = s;
		s->next = q;
		s->prior = q;
	}
	/*if ((Qlist_length(list)== 1)&&(q == first))
	{
		list->next = s;
		s->next = q;
		s->prior = q;
		q->prior = s;
		q->next = s;
		list->slider = s;
	}*/
	if ((Qlist_length(list) > 1) && (q == first))
	{
		list->next = s;
		s->next = q;
		q->prior = s;
		s->prior = last;
		last->next = s;
		list->slider = s;
	}
	if ((Qlist_length(list) > 1) && (q == last))
	{
		q->next = s;
		s->next = first;
		first->prior = s;
		s->prior = q;
	}
	if((q!=first)&&(q!=last)&& (Qlist_length(list) >1))
	{
		s->next = q;
		p->next = s;
		q->prior = s;
		s->prior = p;
	}
	s->data = node;
	list->length++;
	return ret;
}

Qlist* Qlist_get(Qlist* list,int pos)
{
	Qlist* p = list;
	int ret=-1;
	int i = 0;
	ret = (list != NULL);
	if(ret)
		for (i = 0; i <= pos; i++)
		{
			p = p->next;
		}
	return p;
}

void Qlist_delete(Qlist* list, int pos)
{
	Qlist* p = list;
	Qlist* q = NULL;
	int i = 0;
	int ret=-1;
	ret = (list != NULL) && (pos >= 0);
	if (ret)
	{
		Qlist* first = list->next;
		Qlist* last = Qlist_get(list, (list->length - 1));
		for (i = 0; i < pos; i++)
		{
			p = p->next;
		}
		q = p->next;
		if (Qlist_length(list) == 1)
		{
			list->next = list;
			list->prior = list;
			list->slider = NULL;
		}
		if ((first==q)&& (Qlist_length(list)==2))
		{
			list->next = last;
			last->prior = last;
			last->next = last;
		}
		if ((first == q) && (Qlist_length(list) > 2))
		{
			list->next = q->next;
			q->next->prior = last;
			last->next = q->next;
		}
	    if ((last == q)&& (Qlist_length(list)==2))
		{
			p->next = p;
			p->prior = p;
		}
		if ((last == q) && (Qlist_length(list) > 2))
		{
			p->next = first;
			first->prior = p;
		}
		if ((q != first) && (q != last)&& (Qlist_length(list) >2))
		{
			p->next = q->next;
			q->next->prior = p;
		}
		if(list->slider==q)
		{
			list->slider = list->slider->next;
		}
		if (list->length == 0)
		{
			list->prior = list;
			list->next = list;
			list->slider = NULL;
		}
		free(q);
		q = NULL;
		list->length--;
	}
}

void Qlist_delete_slider(Qlist* list, int j)
{
	int i = 0;
	Qlist* p = list->next;
	if (list != NULL)
	{
		for (i = 0; i < list->length; i++)
		{
			if (p->data ==j)
				break;
			else
				p = p->next;
		}
	}
	if (p->data != j)
	{
		printf("can't find\n");
		exit(0);
	}
	else
	{
		Qlist_delete(list, i);
	}
}

Qlist* Qlist_reset_slider(Qlist* list)
{
	Qlist* p = list->slider;
	if (list != NULL)
	{
		p= list->next;
	}
	return p;
}

Qlist* QList_get_slider(Qlist* list)
{
	Qlist* p = NULL;
	if (list != NULL)
	{
		p = list->slider;
	}
	return p;
}

Qlist* QList_moveup_slider(Qlist* list)
{
	Qlist* p = NULL;
	if ((list != NULL) && (list->slider!=NULL))
	{
		p = list->slider;
		list->slider = p->next;
	}
	return p;
}


Qlist* QList_movedown_slider(Qlist* list)
{
	Qlist* p = NULL;
	if ((list != NULL) && (list->slider != NULL))
	{
		p = list->slider;
		list->slider = p->prior;
	}
	return p;
}