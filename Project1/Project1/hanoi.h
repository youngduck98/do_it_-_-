#include"hanoi_stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#ifndef ___hanoi
#define ___hanoi
typedef struct {
	hanoi_stack* A;
	hanoi_stack* B;
	hanoi_stack* C;
	int size;
}hanoi;

//�ϳ���ž �ʱ�ȭ
void hanoi_initialize(hanoi* H, int size);
//�ϳ���ž ���
void hanoi_print(hanoi* H);
//�ϳ���ž Ǯ�� ����Լ�
void hanoi_solve(hanoi*H, int n, hanoi_stack* A, hanoi_stack* B, hanoi_stack* C);
#endif // !__hanoi