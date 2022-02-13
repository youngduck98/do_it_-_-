#include"hanoi.h"
#include"hanoi_stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//typedef struct {
//	intstack* a;
//	intstack* b;
//	intstack* c;
//  int size;
//}hanoi;

//하노이탑 초기화
void hanoi_initialize(hanoi* H, int size) {
	H->A = malloc(sizeof(hanoi_stack));
	H->B = malloc(sizeof(hanoi_stack));
	H->C = malloc(sizeof(hanoi_stack));
	initialize(H->A, size);
	initialize(H->B, size);
	initialize(H->C, size);
	H->size = size;

	int x = 0;
	for (int i = size; i >0; i--) {
		if (push(H->A, &i)) {
			printf("push\n");
		}
		else {
			printf("false");
			return;
		}
	}
}

void hanoi_print(hanoi* H) {
	for (int i = H->size - 1; i >= 0; i--) {
		printf("%3d %3d %3d\n", *(H->A->stk + i), *(H->B->stk + i), *(H->C->stk + i));
	}
}

void hanoi_move(hanoi_stack* A, hanoi_stack* B) {
	int x = 0;
	pop(A, &x);
	push(B, &x);
}

void hanoi_solve(hanoi *H, int n, hanoi_stack* A, hanoi_stack* B, hanoi_stack* C) {
	if (n > 1) {
		hanoi_solve(H, n - 1, A, C, B);
	}
	hanoi_move(A, C);
	printf("\n\n");
	hanoi_print(H);
	if (n > 1) {
		hanoi_solve(H, n - 1, B, A, C);
	}
}
