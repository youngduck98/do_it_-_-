#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#ifndef __hanoi_stack
#define __hanoi_stack

typedef struct {
	char purpose;
	int max;
	int prt;
	int* stk;
}hanoi_stack;

bool initialize(hanoi_stack* s, int max);

bool push(hanoi_stack* s, int* x);

bool pop(hanoi_stack* s, int* x);

bool peek(hanoi_stack* s, int* x);

bool clear(hanoi_stack* s);

bool capacity(const hanoi_stack* s);

int size(const hanoi_stack* a);

int count(const hanoi_stack* a);

bool isEmpty(const hanoi_stack* s);

bool isfull(const hanoi_stack* s);

bool search(const hanoi_stack* s, int* key, int* x);

void delete_Stack(hanoi_stack* s);
#endif // !__hanoi_stack