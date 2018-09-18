#include "tlist.h"

void display(tlist* head, void(*print)(tlist*))
{
	tlist* q = head->next;
	while (q)
	{ 
		print(q);
		q = q->next;
	}
	printf("\n");
}

tlist* create_list() /*create a empty list*/
{
	tlist* head = (tlist*)calloc(1, sizeof(struct node));
	if (head == NULL)
		return NULL;
	head->data  = NULL;
	head->next  = NULL;
	head->prior = NULL;
	return head;
}

int list_is_empty(tlist* head) /*whether the list is empty*/
{
	if (head == NULL)
		return -1;
	return ((head->next == head->prior) ? 1 : 0);
}

int get_list_length(tlist* head) /*get the length of list*/
{
	if (head == NULL)
		return -1;
	int i = 0;
	tlist* p = head->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

int insert_by_pos(tlist* head, int pos, data_t data) /*insert data into list by position*/
{
	if (head == NULL)
		return -1;
	if (pos < 0 || pos > get_list_length(head))
		return -1;
	tlist* q = head;
	while (pos--)
		q = q->next;
	tlist* p = (tlist*)calloc(1, sizeof(struct node));
	if (p == NULL)
		return -1;
	p->data  = data;
	p->next  = NULL;
	p->prior = NULL;
	if (p->next == NULL)
	{
		p->prior = q;
		q->next = p;
	}
	else
	{
		p->next = q->next;
		q->next->prior = p;
		p->prior = q;
		q->next = p;
	}
	return 0;
}

int del_element_bypos(tlist* head, int pos) /*delete data from list by position*/
{
	if (head == NULL)
		return -1;
	if (pos < 0 || pos > get_list_length(head) - 1)
		return -1;
	tlist* q = head;
	tlist* p = head;
	while (pos--)
		q = q->next;
	p = q->next;
	if (p->next == NULL)
	{
		q->next  = NULL;
		p->prior = NULL;
		free(p);
		p->next = NULL;
		p->prior = NULL;
	}
	else
	{
		q->next = p->next;
		p->next->prior = q;
		free(p);
		p->next = NULL;
		p->prior = NULL;
	}
	return 0;
}

int del_element_bydata(tlist* head, data_t data) /*delete data from list by data*/
{
	if (head == NULL)
		return -1;
	int i = 0;
	tlist* q = head->next;
	while ((q->data != data) && q)
	{
		i++;
		q = q->next;
	}
	del_element_bypos(head, i);
	return 0;
}

int find_ele_by_data(tlist* head, data_t data) /*find data and return position*/
{
	if (head == NULL)
		return -1;
	tlist* q = head->next;
	int i = 0;
	while ((q->data != data) && q)
	{
		q = q->next;
		i++;
	}
	return i;
}

int change_data_bydata(tlist* head, data_t old, data_t new) /*change the node data*/
{
	if (head == NULL)
		return -1;
	int i = find_ele_by_data(head, old);
	tlist* q = head;
	while ((i--) && q)
		q = q->next;
	q = q->next;
	q->data = new;
	return 0;
}

void clear_list(tlist* head) /*clear the list except the head node*/
{
	if (head == NULL)
		return;
	tlist* p = head;
	tlist* q = head->next;
	while (q)
	{
		p = q->next;
		free(q);
		q = p;
	}
	head->next = NULL;
}

void destory_list(tlist* head)
{
	if (head == NULL)
		return;
	clear_list(head);
	free(head);
	head = NULL;
}

