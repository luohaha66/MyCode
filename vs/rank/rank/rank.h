#pragma once
#ifndef _RANK_H_
#define _RANK_H_

void swap(int *a, int i, int j);

void display(int* a, int len);

void order_rank(int* a, int len);

void bubbling_rank(int *a, int len);

void shell_insert_rank(int* a, int len);

int location_rank(int* a, int head, int end);

void repeat_rank(int*a, int head, int end);

void quick_rank(int* a, int head, int end);

void Merge_rank(int* src, int* des, int head, int mid, int end);

void MSort_rank(int* src, int* des, int head, int end, int max);

void MergeSort_rank(int *array, int len);
#endif // !_RANK_H_
