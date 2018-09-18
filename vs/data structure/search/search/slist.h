#pragma once
#ifndef _SLIST_H_
#define _SLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 100

typedef struct stu {
	int id;
	char name[30];
	int age;
}stu;

typedef stu data;
typedef struct slist {
	data list_data[size];
	int  last;
}slist;

slist* creatslist();
void display(slist* list, void(*print)(slist* list, int i));
int slist_is_empty(slist* list);
int slist_is_full(slist* list);
int get_slist_length(slist* list);
int insert_data(slist* list, int pos, data c);
data get_data_atpos(slist* list, int i);
int del_data_pos(slist* list, int pos);
int del_data_data(slist* list, data c);
int find_element_data(slist* list, data c);
int find_and_replace(slist* list, data a, data c);
void slist_destory(slist* list);

#endif // !_SLIST_H_