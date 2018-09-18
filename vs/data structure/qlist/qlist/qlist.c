#include "qlist.h"

void display(qlist* head, void(*print)(qlist*))
{
	if (head == NULL)
		return;
	qlist* q = head->next;
	do
	{
		print(q);
		q = q->next;
	} while (q);
	printf("\n");
}

qlist* createqlist() /*create linklist*/
{
	qlist* head = (qlist*)calloc(1, sizeof(struct node));
	if (head == NULL)
		return NULL;
	head->data = NULL;
	head->next = NULL;
	return head;
}

int qlist_is_empty(qlist* head) /*judge the linklist is empty*/
{
	if (head == NULL)
		return -1;
	return ((head->next == NULL) ? 1 : 0);
}

int qlist_ele_number(qlist* head) /*get the element's data*/
{
	if (head == NULL)
		return -1;
	int i = 0;
	qlist* q = head;
	while (q->next)
	{
		i++;
		q = q->next;
	}
	return i;
}

int insert_into_qlist(qlist* head, int pos, data_t c) /*insert data into qlist*/
{
	if (head == NULL)
		return -1;
	if (pos < 0 || pos > qlist_ele_number(head))
		return -1;
	qlist* node = (qlist*)calloc(1, sizeof(node));
	if (node == NULL)
		return -1;
	node->next = NULL;
	node->data = c;
	qlist* q = head;
	while (pos--)
		q = q->next;
	node->next = q->next;
	q->next = node;
	return 0;
}

int del_from_qlist(qlist* head, int pos) /*del data from qlist bu position*/
{
	if (head == NULL)
		return -1;
	if (pos < 0 || pos > qlist_ele_number(head) - 1)
		return -1;
	qlist* p = head;
	qlist* q = head;
	while (pos--)
		p = p->next;
	q = p->next;
	free(q);
	q = NULL;
	return  0;
}

int del_ele_bydata(qlist* head, data_t c) /*del element from list by data*/
{
	if (head == NULL)
		return -1;
	int i = 0;
	qlist* q = head->next;
	while (q->data != c && q)
	{
		q = q->next;
		i++;
	}
	if (i == qlist_ele_number(head))
		return -1;
	else
		del_from_qlist(head, i);
	return 0;
}

qlist* find_ele_bypos(qlist* head, int pos) /*according position to find node*/
{
	if (head == NULL)
		return NULL;
	if (pos < 0 || pos > qlist_ele_number(head) - 1)
		return NULL;
	qlist* q = head;
	while (pos-- && q)
		q = q->next;
	q = q->next;
	return q;
}

qlist* find_ele_bydata(qlist* head, data_t c) /*according data to find node*/
{
	if (head == NULL)
		return NULL;
	qlist* q = head->next;
	while ((c != q->data) && q)
		q = q->next;
	return q;
}

int change_data_bypos(qlist* head, int pos, data_t c) /*according pos to change node data*/
{
	if (head == NULL)
		return -1;
	if (pos < 0 || pos > qlist_ele_number(head) - 1)
		return -1;
	qlist* q = find_ele_bypos(head, pos);
	if (q == NULL)
		return -1;
	q->data = c;
	return 0;
}

int change_data_bydata(qlist* head, data_t old, data_t new) /*according data to change node data*/
{
	if (head == NULL)
		return -1;
	qlist* q = find_ele_bydata(head, old);
	if (q == NULL)
		return -1;
	q->data = new;
	return 0;
}

void clear_qlist(qlist* head) /*clear the list*/
{
	if (head == NULL)
		return;
	/*int len = qlist_ele_number(head);
	while (len-- && head)
		del_from_qlist(head, 0);*/
	slist* q = head;
	slist* p = head->next;
	while(q)
	{
		q = p->next;
		free(p);
		p = q; 
	}
	head->next = NULL;
}

void destory_slist(qlist* head) /*destory the list*/
{
	if (head == NULL)
		return;
	clear_qlist(head);
	free(head);
}