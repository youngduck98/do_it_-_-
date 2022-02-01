#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"stack_d.h"

//typedef struct {
//	int max;
//	int sp_a;
//	int sp_b;
//	int* stack;
//}IntStack_d;

int* stack_bs(IntStack_d* s) {
	return s->stack + s->max - 1;
}

bool initialize_stack_d(IntStack_d* s, int max) {
	s->stack = malloc(sizeof(int) * max);
	s->max = max;
	s->sp_a = 0;
	s->sp_b = 0;
	if (_msize(s->stack) == sizeof(int) * max) {
		return true;
	}
	else {
		return false;
	}
}

bool push_a(IntStack_d* s, int x) {
	if (s->sp_a + s->sp_b >= s->max) {
		return false;
	}
	else {
		*(s->stack + s->sp_a) = x;
		s->sp_a++;
		return true;
	}
}

bool push_b(IntStack_d* s, int x) {
	if (s->sp_a + s->sp_b >= s->max) {
		return false;
	}
	else {
		*(stack_bs(s) - s->sp_b) = x;
		s->sp_b++;
		return true;
	}
}

bool pop_a(IntStack_d* s, int* x) {
	if (s->sp_a <= 0) {
		return false;
	}
	else {
		*x = *(s->stack + s->sp_a);
		s->sp_a--;
		return true;
	}
}

bool pop_b(IntStack_d* s, int* x) {
	if (s->sp_b <= 0) {
		return false;
	}
	else {
		*x = *(stack_bs(s) - s->sp_b);
		s->sp_b--;
		return true;
	}
}

void print_stack_d(IntStack_d* s) {
	int x = 0;
	printf("a\n");
	for (int i = 0; i < s->sp_a; i++) {
		printf("%d", *(s->stack + i));
	}
	printf("\nb\n");
	for (int i = 0; i < s->sp_b; i++) {
		printf("%d", *(stack_bs(s)-i));
	}
}