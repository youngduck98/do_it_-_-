#pragma once
#include<stdio.h>
#include<stdbool.h>
#ifndef ___cell_sort
#define ___cell_sort

void cell_sort(int* a, int m, bool(*fp)(void*, void*));
void insert_sort(int* a, int m);
void print_ary(int* a, int m);
bool cmp_u(int* a, int* b);

#endif // !___cell_sort.h
