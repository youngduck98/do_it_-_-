#include<stdio.h>
#include<stdbool.h>

bool cmp_u(int a, int b) {
	if (a > b)
		return true;
	else
		return false;
}

void int_swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void sort_selection(int* a, int m, bool (*fp)(int* , int* )) {
	for (int i = 0; i < m-1; i++) {
		for (int k = i + 1; k < m; k++) {
			if (fp(*(a + i), *(a + k))) {
				int_swap(a + i, a + k);
			}
		}
	}
}


int main() {
	int a[10] = { 9,8,7,6,5,4,3,2,1, 0 };
	sort_selection(a, 10, cmp_u);
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
}