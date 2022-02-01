#pragma once
#include<stdio.h>
#include<stdbool.h>

#ifndef ___stack_d
#define ___stack_d

typedef struct {
	int max;
	int sp_a;
	int sp_b;
	int* stack;
}IntStack_d;

int* stack_bs(IntStack_d* s);

bool initialize_stack_d(IntStack_d* s, int max);

bool push_a(IntStack_d* s, int x);

bool push_b(IntStack_d* s, int x);

bool pop_a(IntStack_d* s, int* x);

bool pop_b(IntStack_d* s, int* x);

void print_stack_d(IntStack_d* s);
#endif // stack_d.h
