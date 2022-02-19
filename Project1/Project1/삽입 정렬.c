#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


void print_ary(int* a, int m) {
	for (int i = 0; i < m; i++) {
		printf("%2d", *(a + i));
	}
	printf("\n");
}

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
	if (*a >= *b) {
		return true;
	}
	else {
		return false;
	}
}

bool print_process(int a, int b) {
	for (int i = 0; i <= b; i++) {
		if (i == a)
			printf("%2c", '+');
		else if (i == b)
			printf("%2c", '*');
		else
			printf("%2c", ' ');
	}
	printf("\n");
}

int binary_search(int* a, int m, int n, int c1, int c2, bool(*fp)(void*, void*)) {
	if (c1 >= c2) {
		if (fp(a + c2, a + n) || *(a + c2) == *(a + n)) {
			return c2;
		}
		else {
			return c2 + 1;
		}
	}

	if (*(a + (c1 + c2) / 2) == *(a + n)) {
		return (c1 + c2) / 2;
	}
	else if (fp(a + (c1 + c2) / 2, a + n)) {
		return binary_search(a, m, n, c1, (c1 + c2) / 2 - 1, fp);
	}
	else {
		return binary_search(a, m, n, (c1 + c2) / 2 + 1, c2, fp);
	}
}

void binary_sort(int* a, int m, int n, int c1, int c2, bool (*fp)(void*, void*)) {
	print_ary(a, m);
	if (m <= n) {
		return;
	}
	if (c1 >= c2 && fp(a + c2, a + n)) {
		move_ary(a, m, n, c2);
		binary_sort(a, m, n + 1, 0, n, fp);
		return;
	}
	else if (c1 >= c2 && !fp(a + c2, a + n)) {
		move_ary(a, m, n, c2+1);
		binary_sort(a, m, n + 1, 0, n, fp);
		return;
	}

	if (*(a + n + 1) == *(a + (c1+c2)/2)) {
		move_ary(a, m, n, (c1 + c2) / 2);
		binary_sort(a, m, n + 1, 0, n, fp);
		return;
	}
	else if (fp(a + (c1 + c2) / 2, a + n)) {
		binary_sort(a, m, n, c1, (c1 + c2) / 2 - 1, fp);
		return;
	}
	else {
		binary_sort(a, m, n, (c1 + c2) / 2 + 1, c2, fp);
		return;
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
	/*for (int i = 0; i < n; i++) {
		if (fp(a+i, &b)) {
			print_process(i, n);
			print_ary(a, m);
			move_ary(a, m, n, i);
			break;
		}
	}*/
	int i = binary_search(a, m, n, 0, n, fp);
	print_process(i, n);
	print_ary(a, m);
	move_ary(a, m, n, i);
	insert_sort(a, m, n + 1, fp);
}

void insert_sort2(int* a, int m, bool (*fp)(int* ,int*)) {
	int tmp = 0;
	int j = 0;
	for (int i = 1; i < m; i++) {
		tmp = a[i];
		for (j = i; j >= 1 && !fp(a+j-1,&tmp); j--) {
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}
}


int main() {
	int a[] = { 1,2,3,4,5,6,7,10,9,8 };
	//binary_sort(a, 10, 1, 0, 0, cmp_u);
	//insert_sort(a, 10, 0, cmp_u);
	insert_sort2(a, 10, cmp_u);
	print_ary(a, 10);
}