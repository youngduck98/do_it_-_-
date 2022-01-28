#include<stdio.h>
#include<stdlib.h>
#define N 5

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void reverse(int* i) {
	int n = _msize(i) / sizeof(*i);//_msize: 포인터에 할당된 크기를 구한다.
	for (int k = 0; k < n/2; k++) {
		swap(i+k,i+(n-k-1) );
	}
}

int main() {
	int *i;
	i = calloc(N, sizeof(int));
	for (int a = 0; a < N; a++) {
		*(i + a) = a;
	}
	reverse(i);

	for (int a = 0; a < N; a++) {
		printf("%d", *(i+a));
	}

	free(i);
}
