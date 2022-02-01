#include<stdio.h>
#include<stdbool.h>

#ifndef __IntStack
#define __IntStack

typedef struct {
	int max;
	int prt;
	int* stk;
}IntStack;

bool initialize(IntStack* s, int max);

bool push(IntStack* s, int* x);

bool pop(IntStack* s, int* x);

bool peek(IntStack* s, int* x);

bool clear(IntStack* s);

bool capacity(const IntStack* s);

int size(const IntStack* a);

bool isEmpty(const IntStack* s);

bool isfull(const IntStack* s);

bool search(const IntStack* s, int *key, int* x);

void delete_Stack(IntStack* s);
#endif // !__IntStack