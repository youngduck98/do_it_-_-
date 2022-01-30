#include<stdio.h>
#include<stdlib.h>

int int_cmp(const int* a, const int* b) {
	if (*a < *b)
		return -1;
	else if (*a > *b) {
		return 1;
	}
	else
		return 0;
}

int main() {
	int a[] = { 1,2,3,4,8,9,10,11,12 };
	int key = 9;

	int* p = bsearch(&key, a, sizeof(a) / sizeof(*a), sizeof(*a), int_cmp);
	//해당 key가 있는 주소 값을 반환함.
	printf("%d\n", p-a);
	for (int i = 0; i < 9; i++) {
		printf("%d ", a[i]);
	}
}