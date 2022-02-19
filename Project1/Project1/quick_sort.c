#include"quick.h"

void movenum_ary(int* a, int m, int k, int d) {
	int tmp = 0;
	if (k == d) {
		return;
	}
	else if (k > d) {
		tmp = a[k];
		for (int i = k; i > d; i--) {
			a[i] = a[i - 1];
		}
		a[d] = tmp;
	}
	else {
		tmp = a[k];
		for (int i = k; i < d; i++) {
			a[i] = a[i + 1];
		}
		a[d] = tmp;
	}
}

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void quick_sort2(int* a, int m) {
	if (m <= 1) {
		return;
	}
	int pl = 0;
	int pr = m - 1;
	do {
		while (a[m / 2] > a[pl])pl++;
		while (a[m / 2] < a[pr])pr--;
		if (pl <= pr) {
			swap(a + pl, a + pr);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (pr<0 || pl>m - 1) {
		return;
	}
	print_ary(a, m);
	quick_sort2(a, pl);
	quick_sort2(a + m - pr, pr);
}

void quick_sort(int* a, int m) {
	print_ary(a, m);
	if (m <= 1) {
		return;
	}
	int s = 0;
	int b = 0;
	int head = a[0];
	int m1 = m;
	for (int i = 1; i < m1; i++) {
		if (head > a[i]) {
			movenum_ary(a, m, i, 0);
			s++;
		}
		else {
			movenum_ary(a, m, i, m - 1);
			i--;
			m1--;
			b++;
		}
	}
	quick_sort(a, s);
	quick_sort(a + s, b);
}

void print_ary(int* a, int m) {
	for (int i = 0; i < m; i++) {
		printf("%2d", a[i]);
	}
	printf("\n");
}

int main() {
	int a[10] = { 7,9,8,10,6,5,4,3,2,1 };
	quick_sort2(a, 10);
	print_ary(a, 10);
}
