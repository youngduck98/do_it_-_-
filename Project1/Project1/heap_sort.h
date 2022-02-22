#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#ifndef ___heep_sort
#define ___heep_sort

int heep_sort(int* a, int m, int n);
int L_child_node(int m, int n);
int R_child_node(int m, int n);
int parent_node(int m, int n);
int down_heep(int* a, int m);
void swap(int*, int*);
void print_heap(int* a, int m);


#endif // !___heep_sort
