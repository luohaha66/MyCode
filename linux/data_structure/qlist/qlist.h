#pragma once
#ifndef _QLIST_H_
#define _QLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int data_t;

typedef struct node {
	data_t data;
	struct node* next;
}qlist;

void display(qlist* head, void(*print)(qlist*));
qlist* createqlist();
int qlist_is_empty(qlist* head);
int qlist_ele_number(qlist* node);
int insert_into_qlist(qlist* head, int pos, data_t c);
int del_from_qlist(qlist* head, int pos);
int del_ele_bydata(qlist* head, data_t c);
qlist* find_ele_bypos(qlist* head, int pos);
qlist* find_ele_bydata(qlist* head, data_t c);
int change_data_bypos(qlist* head, int pos, data_t c);
int change_data_bydata(qlist* head, data_t old, data_t new);
void clear_qlist(qlist* head);
void destory_slist(qlist* head);

#endif // _QLIST_H_
