#include<stdio.h>
#include<stdlib.h>
#include"stack_ex.h"

int main() {
	IntStack* a;
	int x = 0;
	a = malloc(sizeof(IntStack));
	if (initialize(a, 5)) {
		printf("initialize success\n");
	}

	for (int i = 0; i < 5; i++) {
		if (push(a, &i)) {
			printf("push %d success\n", i);
		}
	}
	for (int i = 0; i < 5; i++) {
		if (pop(a, &x)) {
			printf("pop %d success\n", x);
		}
	}
	if (isEmpty(a)) {
		printf("stack is empty\n");
	}
	delete_Stack(a);
}