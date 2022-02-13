#include<stdio.h>
#include<stdbool.h>
#include"hanoi_stack.h"
#include<stdlib.h>

//typedef struct {
//	int max;
//	int prt;
//	int* stk;
//}IntStack;

bool initialize(hanoi_stack* s, int max)
{
	s->stk = malloc(sizeof(int) * max);
	s->prt = 0;
	s->max = max;
	for (int i = 0; i < max; i++) {
		*(s->stk + i) = 0;
	}
	if (_msize(s->stk) == max * sizeof(int)) {
		return true;
	}
	else {
		return false;
	}
}

bool push(hanoi_stack* s, int* x)
{
	if (s->prt == 0 && s->max) {
		*(s->stk + s->prt) = *x;
		s->prt++;
		return true;
	}
	else if (s->prt < s->max && *(s->stk +s->prt-1) > *x) {
		*(s->stk + s->prt) = *x;
		s->prt++;
		return true;
	}
	else {
		return false;
	}
}

bool pop(hanoi_stack* s, int* x) {
	if (isEmpty(s)) {
		return false;
	}
	else {
		s->prt--;
		*x = *(s->stk + s->prt);
		*(s->stk + s->prt) = 0;
		return true;
	}
}

bool peek(hanoi_stack* s, int* x) {
	if (isEmpty(s)) {
		return false;
	}
	else {
		*x = *(s->stk + s->prt-1);
		return true;
	}
}

bool clear(hanoi_stack* s) {
	s->prt = 0;
	return 0;
}

bool capacity(const hanoi_stack* s) {
	return _msize(s->stk);
}

int size(const hanoi_stack* s) {
	return s->max;
}

int count(const hanoi_stack* s) {
	return s->prt + 1;
}

bool isEmpty(const hanoi_stack* s) {
	if (s->prt == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool isfull(const hanoi_stack* s) {
	if (s->prt == s->max) {
		return true;
	}
	else {
		return false;
	}
}

bool search(const hanoi_stack* s, int* key, int* x) {
	for (int i = 0; i < s->prt - 1; i++) {
		if (*(s->stk + i) == *key) {
			return true;
			*x = i;
		}
	}
	return false;
}

void delete_Stack(hanoi_stack* s) {
	free(s->stk);
}