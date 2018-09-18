#pragma once
#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <stdio.h>

int reduce_by_half_search_method(int* a, int len, int i);
void my_display(int* a, int len);
void swap(int* a, int i, int j);
void bubbling_rank(int* a, int len);
void compare_rank(int* a, int len);
void insert_rank(int* a, int len);
void insert_rank_1(int* a, int len);
int find_position(int* a, int head, int end);
void repeat_find(int*a, int head, int end);
void quickly_rank(int* a, int head, int end);
void selection_rank(int*a, int len);
void copy(int* a, int* b, int head, int mid, int end);
void mergesort(int* a, int * b, int head, int end, int max);
void merge_rank(int* a, int len);
#endif // !_SEARCH_H_

