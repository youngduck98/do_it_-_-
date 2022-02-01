#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"stack_d.h"

int main() {
	IntStack_d* a;
	a = malloc(sizeof(IntStack_d));
	initialize_stack_d(a, 10);
	for (int i = 0; i < 3; i++) {
		if (push_a(a, i)) {
			printf("push_a %d success\n", i);
		}
	}
	for (int i = 0;; i++) {
		if (push_b(a, i)) {
			printf("push_b %d success\n", i);
		}
		else {
			printf("push_b %d failed\n", i);
			break;
		}
	}
	print_stack_d(a);
}