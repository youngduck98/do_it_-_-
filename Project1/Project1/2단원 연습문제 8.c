#include<stdio.h>

void ary_copy(int a[], const int b[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = b[n-i-1];
	}
}

int main() {
	int a[] = { 1,2,3,4,5 };
	const int len = sizeof(a) / sizeof(a[0]);
	int b[sizeof(a) / sizeof(a[0])];
	ary_copy(b, a, len);
	for (int i = 0; i < len; i++) {
		printf("%d ", b[i]);
	}
}