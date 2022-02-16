#include<stdio.h>
#include<stdbool.h>

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void print_arr(int* a, int m) {
	for (int i = 0; i < m; i++) {
		printf("%d ", *(a + i));
	}
	printf("\n");
}

void bubble_sort(int* a, int m) {
	int ch = 0;
	for (int i = 0; i < m-1; i++) {
		ch = 0;
		for (int k = i; k < m - 1; k++) {
			if (*(a + k) > *(a + k + 1)) {
				printf("swap %d %d\n", *(a + k), *(a + k + 1));
				swap(a + k, a + k + 1);
				ch++;
			}
		}
		if (ch == 0) {
			break;
		}
	}
}//for문을 사용한 일반 bubble_sort

bool cmp_u(int* a, int* b) {
	if (*a > *b) {
		return true;
	}
	else {
		return false;
	}
}

void d_bubble_sort(int*a, int m, int n, bool (*fp)(int*, int*)) {
	int key = 0;
	if (n % 2 == 0) {
		for (int i = n; i <m-1; i++) {
			if (fp(a+i,a+i+1)) {
				swap(a + i, a + i + 1);
				key++;
			}
		}
	}
	else {
		for (int i = m - 1; i > n; i--) {
			if (fp(a + i - 1, a + i)) {
				swap(a + i, a + i + 1);
				key++;
			}
		}
	}
	if (key == 0 || n >= m - 2) {
		return;
	}
	d_bubble_sort(a, m, n + 1, fp);
}

int main() {
	int a[10] = { 1,2,3,4,5,6,7,9,8,10 };
	d_bubble_sort(a, 10, 0, cmp_u);
	print_arr(a, 10);
}