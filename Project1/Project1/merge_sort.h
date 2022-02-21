#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#ifndef ___merge_sort
#define ___merge_sort

int* merge_sort(int* a, int m);
void print_ary(int* a, int m);
bool mergesort2(int* a, int n);
void merge_sort2(int a[], int left, int right, int* buff);
#endif // !___merge_sort
