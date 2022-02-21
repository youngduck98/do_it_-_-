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

bool cmp_u(int* a, int* b)
{
	printf("%d %d\n", *a, *b);
	if (*a < *b) return true;
	else return false;
}

void print_c_ary(char* a, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < n; k++) {
			printf("%c", *(a + n * i + k));
		}
		printf("\n");
	}
}

void quick_sort2(int* a, int m, bool (*fp)(int* , int* )) {
	int pl = 0;
	int pr = m-1;
	int x = a[m/ 2];
	do {
		printf("x: %d\n", x);
		while (fp(a + pl, &x)) {
			if (a[pl] == x) break;
			pl++;
		}
		while (fp(&x, a + pr)) {
			if (a[pr] == x) break;
			pr--;
		}
		printf("pl, pr: %d %d\n", pl, pr);
		print_ary(a, m);
		if (pl <= pr) {
			swap(a + pl, a + pr);
			pl++;
			pr--;
		}
		print_ary(a, m);
		printf("\n");
	} while (pl <= pr);
	if (pl<m-1)quick_sort2(a + pl, m-pl, fp);
	if (pr>0)quick_sort2(a, pr+1, fp);
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

void test(char *a) {
	printf("%c", *(a+7));
}

int main() {
	int a[10] = { 7,9,8,10,1,5,4,3,2,6 };
	char c[4][7] = { "lisp", "c", "ada", "pascal" };
	//printf("%c", **c);//배열 이라는 것을 main내에서 기억하고 있어 가능한 방법
	//배열 자체를 넘기고 싶다면 a[][7]이나 (*a)[7]이용
	//test(c);//넘겨질 때 더블 포인터가 아니라 그냥 그 주소가 넘어간다.
	print_ary(a, 10);
	quick_sort2(a, 10, cmp_u);
	print_ary(a, 10);
	//print_ary(c, 4);
}
