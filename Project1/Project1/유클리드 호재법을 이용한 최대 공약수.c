#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int uclid_gcf(int x, int y) {
	if (y == 0) {
		return x;
	}
	return uclid_gcf(y, x % y);
}

int gcd_ary(int a[], int n) {
	if (n == 1) {
		return *a;
	}
	else if (n == 2) {
		return uclid_gcf(*(a + 1), *(a));
	}
	else {
		*(a + 1) = uclid_gcf(*(a + 1), *(a));
		return gcd_ary(a + 1, --n);
	}
}

int main() {
	printf("%d", uclid_gcf(25, 15));
	int a[3] = { 9,18,30 };
	printf("\n%d", gcd_ary(a, 3));
}