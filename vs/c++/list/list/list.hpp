#ifndef _LIST_HPP_
#define _LIST_HPP_

#include "list.h"

using namespace std;

template <class T>
list<T>::list()
{
	head = new qlist;
	head->next = NULL;
	length = 0;
}

template <class T>
list<T>::~list()
{
	qlist* q = head;
	qlist* p = head->next;
	while(p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	delete head;
	head = NULL;
}

template <class T>
void list<T>::insert(int pos, T d)
{
	if (head == NULL || pos > length)
		return;
	qlist* node = new qlist;
	if (node == NULL)
		return;
	qlist* q = head;
	node->data = d;
	node->next = NULL;
	while (pos--)
		q = q->next;
	node->next = q->next;
	q->next = node;
	length++;
}

template <class T>
T list<T>::del(int pos)
{
	if (head == NULL || pos > length)
		return -1;
	T c;
	qlist* q = head;
	qlist* p = head;
	while (pos--)
		q = q->next;
	p = q->next;
	q->next = p->next;
	c = p->data;
	delete p;
	p = NULL;
	length--;
	return c;
}

template <class T>
void list<T>::change_bypos(int pos, T d)
{
	if (head == NULL)
		return;
	qlist* q = head;
	while (pos--)
		q = q->next;
	q = q->next;
	q->data = d;
}

template <class T>
T list<T>::query_by_pos(int pos)
{
	if (head == NULL)
		return -1;
	qlist* q = head;
	while (pos--)
		q = q->next;
	q = q->next;
	return q->data;
}

template <class T>
void list<T>::display()
{
	qlist* q = head->next;
	do
	{
		cout << q->data << " ";
		q = q->next;
	} while (q);
	cout << endl;
}

#endif // !_LIST_HPP_