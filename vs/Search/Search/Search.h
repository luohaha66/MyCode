#pragma once
#ifndef _SEARCH_H_
#define _SEARCH_H_

#include "list.h"
#define MAX 15

void display_slist(Slist* list);

void search_data(int head,int end,int j);

void swap(int* a, int i, int j);

void maopao_rank(Slist* list);

int binary_rank(Slist* list, int head, int end, int j);

int interpolation_search(Slist* list, int head, int end, int key);

void search_not_pair(int* a, int len);

void search_not_pai_2(int* a, int len);
#endif // !_SEARCH_H_
