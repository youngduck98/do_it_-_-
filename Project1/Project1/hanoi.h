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

//하노이탑 초기화
void hanoi_initialize(hanoi* H, int size);
//하노이탑 출력
void hanoi_print(hanoi* H);
//하노이탑 풀이 재귀함수
void hanoi_solve(hanoi*H, int n, hanoi_stack* A, hanoi_stack* B, hanoi_stack* C);
#endif // !__hanoi