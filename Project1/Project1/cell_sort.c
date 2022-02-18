#include<stdlib.h>
#include"cell_sort.h"

void cell_sort(int* a, int m, bool (*fp)(void* ,void*)) {
	int tmp = 0;
	int p = 0;
	int h = 0;
	for (; h < m / 4; h = 2 * h + 1);

	for (h = 3; h >= 1; h /= 2) {
		for (int g = 0; g < h; g++) {
			for (int k = g; k < m; k += h) {
				tmp = a[k];
				for (p = k; p >= h && !fp(a+p-h, &tmp); p -= h) {
					a[p] = a[p - h];
					//어떤 구역 뒤에 있는 것을 빼서 앞쪽에 집어 넣는 것이므로 뒤 부터 계산한다면 간편하다.
				}
				a[p] = tmp;
			}
		}
	}
}

bool cmp_u(int* a, int* b) {
	if (*a < *b) {
		return true;
	}
	else {
		return false;
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
	int a[9] = { 9,10,7,8,6,4,5,3,2 };
	cell_sort(a, 9, cmp_u);
	//insert_sort(a, 9);
	print_ary(a, 9);
}