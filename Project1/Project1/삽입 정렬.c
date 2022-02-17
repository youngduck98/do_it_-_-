#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

void move_ary(int* a, int m, int n, int k) {
	if (n >= m) {
		printf("false\n");
		return;
	}
	int b = *(a + n);
	for (int i = n; i > k; i--) {
		*(a + i) = *(a + i - 1);
	}
	*(a + k) = b;
}

bool cmp_u(int* a, int* b) {
	if (*a > *b) {
		return true;
	}
	else {
		return false;
	}
}

void insert_sort(int* a, int m, int n, bool (*fp)(void* , void* )) {
	if (n == 0) {
		insert_sort(a, m, n + 1, fp);
		return;
	}
	else if (m <= n) {
		return;
	}
	int b = *(a + n);
	for (int i = 0; i < n; i++) {
		if (fp(a+i, &b)) {
			move_ary(a, m, n, i);
			break;
		}
	}
	insert_sort(a, m, n + 1, fp);
}

void print_ary(int* a, int m) {
	for (int i = 0; i < m; i++) {
		printf("%2d", *(a + i));
	}
}


int main() {
	int a[] = { 1,2,3,4,5,6,7,10,9,8 };
	insert_sort(a, 10, 0, cmp_u);
	print_ary(a, 10);
}