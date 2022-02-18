#include<stdlib.h>
#include"cell_sort.h"

void cell_sort(int* a, int m) {
	int tmp = 0;
	int k = 0;
	for (int h = m / 2; h >= 1; h /= 2) {
		for (int j = 0; j < h; j ++) {
			for (int p = j; p < m; p += h) {
				tmp = a[p];
				for (k = p; k >= h && a[k - h] > tmp; k -= h) {
					a[k] = a[k - h];
				}
				a[k] = tmp;
				print_ary(a, m);
			}
		}
	}
}

void print_ary(int* a, int m) {
	for (int i = 0; i < 9; i++) {
		printf("%2d", a[i]);
	}
	printf("\n");
}

void insert_sort(int* a, int m) {
	int k = 0;
	int tmp = 0;
	for (int j = 0; j < m; j++) {
		tmp = a[j];
		for (k = j; k >= 1 && a[k - 1] < a[j]; k-=1) {
			a[k] = a[k - 1];
		}
		a[k] = tmp;
	}
}

int main() {
	int a[9] = { 9,10,8,7,6,5,4,3,2 };
	cell_sort(a, 9);
	//insert_sort(a, 9);
	print_ary(a, 9);
}