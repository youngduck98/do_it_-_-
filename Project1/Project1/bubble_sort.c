#include<stdio.h>
#include<stdbool.h>

void swap(int* a, int* b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

bool cmpr_u(int* a, int* b) {
	if (*a > *b) {
		return true;
	}
	else {
		return false;
	}
}

bool cmpr_d(int* a, int* b) {
	if (*a < *b) {
		return true;
	}
	else {
		return false;
	}
}

void bubble_sort(int *a, int m, int n, bool (*fp)(int*, int*)) {
	for (int i = m-1; i >= n+1; --i) {
		if (fp(a+i-1,a+i)) {
			swap((a + i), (a + i - 1));
		}
	}
	if (n < m) {
		bubble_sort(a, m, n + 1, fp);
	}
}//오름차순

int main() {
	int a[10] = { 10,8,9,7,6,5,4,3,2,1 };
	bool (*fp);
	fp = cmpr_u;
	bubble_sort(a, 10, 0, fp);
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
}