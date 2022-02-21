#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void movenum_ary(int* a, int m, int k, int d);//배열 내의 수의 위치를 옮기는 함수(k->d)
void quick_sort(int* a, int m);//quick_sort 함수
void print_ary(int* a, int m);//배열 출력 함수
void quick_sort2(int* a, int m, bool(*fp)(void**, void**));
void swap(int*, int*);
bool s_cmp_u(char**, char**);
