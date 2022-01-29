#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void reverse(const int a[], int n) {
	printf("���� �迭: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	for (int i = 0; i < n / 2; i++) {
		swap(a + i, a + n - 1 - i);
		printf("a[%d]�� a[%d]�� ��ȯ�մϴ�.\n", i, n-1-i);
		for (int k = 0; k < n; k++) {
			printf("%d ", a[k]);
		}
		printf("\n");
	}
	printf("���� ������ �����մϴ�.");
}

int main() {
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	reverse(a, sizeof(a) / sizeof(*a));
}