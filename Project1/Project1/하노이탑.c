#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"hanoi.h"

int main() {
	hanoi* H = malloc(sizeof(hanoi));
	hanoi_initialize(H, 10);
	printf("\n\n");
	hanoi_solve(H, H->size,H->A, H->B, H->C);
}