#include<stdio.h>

int linear_search(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] == a[n]) {
			return i;
			break;
		}
	}
	return -1;
}

int main() {
	int a[7] = { 1,2,3,4,5,6 };
	a[6] = 3;
	int i = linear_search(a, 6);
	if (i == -1) {
		printf("fail");
	}
	else {
		printf("a[%d]", i);
	}
}