#pragma once
#include"ary.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void print_ary(int* a, int m) {
	for (int i = 0; i < m; i++) {
		printf("%3d", a[i]);
	}
	printf("\n");
}
