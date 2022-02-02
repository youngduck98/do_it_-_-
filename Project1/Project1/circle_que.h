#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#ifndef ___circle_que
#define ___circle_que

typedef struct {
	int max;
	int num;
	int sq;
	int eq;
	int* que;
}que_a;

bool initialize(que_a* s, int max);

bool enque(que_a* s, int x);

bool deque(que_a* s, int* x);

bool peek(que_a* s, int* x);

bool claer(que_a* s);

bool isempty(que_a* s);

bool isfull(que_a* s);

int capacity(que_a* s);

int size(que_a* s);

void print_que_a(que_a* s);

#endif // !___circle_que


