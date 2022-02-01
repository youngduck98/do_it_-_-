#include<stdio.h>
#include<stdbool.h>
#include"stack_ex.h"
#include<stdlib.h>

//typedef struct {
//	int max;
//	int prt;
//	int* stk;
//}IntStack;

bool initialize(IntStack* s, int max)
{
	s->stk = malloc(sizeof(int) * max);
	s->prt = 0;
	s->max = max;
	if (_msize(s->stk) == max * sizeof(int)) {
		return true;
	}
	else {
		return false;
	}
}

bool push(IntStack* s, int* x)
{
	if (s->prt < s->max) {
		*(s->stk + s->prt) = *x;
		s->prt++;
		return true;
	}
	else {
		return false;
	}
}

bool pop(IntStack* s, int* x) {
	if (isEmpty(s)) {
		return false;
	}
	else {
		s->prt--;
		*x = *(s->stk + s->prt);
		return true;
	}
}

bool peek(IntStack* s, int* x) {
	if (isEmpty(s)) {
		return false;
	}
	else {
		*x = *(s->stk + s->prt);
		return true;
	}
}

bool clear(IntStack* s) {
	s->prt = 0;
	return 0;
}

bool capacity(const IntStack* s) {
	return _msize(s->stk);
}

int size(const IntStack* s) {
	return s->max;
}

bool isEmpty(const IntStack* s) {
	if (s->prt == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool isfull(const IntStack* s) {
	if (s->prt == s->max) {
		return true;
	}
	else {
		return false;
	}
}

bool search(const IntStack* s, int* key, int *x) {
	for (int i = 0; i < s->prt - 1; i++) {
		if (*(s->stk + i) == *key) {
			return true;
			*x = i;
		}
	}
	return false;
}

void delete_Stack(IntStack* s) {
	free(s->stk);
}