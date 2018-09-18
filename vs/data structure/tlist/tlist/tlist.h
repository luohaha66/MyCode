#ifndef _TLIST_H_
#define _TLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
typedef struct node {
	data_t data;
	struct node* prior;
	struct node* next;
}tlist;

void display(tlist* head, void(*print)(tlist*));
tlist* create_list();
int list_is_empty(tlist* head);
int get_list_length(tlist* head);
int insert_by_pos(tlist* head, int pos, data_t data);
int del_element_bypos(tlist* head, int pos);
int del_element_bydata(tlist* head, data_t data);
void clear_list(tlist* head);
int find_ele_by_data(tlist* head, data_t data);
int change_data_bydata(tlist* head, data_t old, data_t new);
void destory_list(tlist* head);

#endif // !_TLIST_H_

