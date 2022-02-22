#include<stdio.h>
#include"frequency_sort.h"
#include<memory.h>
int* frequency_sort(int* a, int m) {
	int max = 0;
	int min = a[0];
	for (int i = 0; i < m; i++) {
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
	}
	int k = max - min + 1;
	int* b = (int*)malloc(sizeof(int) * 10);
	int* c = (int*)malloc(sizeof(int) * m);

	memset(b, 0, sizeof(int) * k);

	for (int i = 0; i < m; i++) ++b[a[i] - min];
	for (int i = 1; i <k; i++) b[i] += b[i - 1];
	print_ary(b, k);
	for (int i = 0; i < m; i++)c[--b[a[i] - min]] = a[i];
	free(b);
	return c;
}