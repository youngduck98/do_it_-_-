#include<stdio.h>

int minof(const int a[], int n) {
	int min = a[0];
	for (int i = 0; i < n; i++) {
		if (min > a[i]) {
			min = a[i];
		}
	}
	return min;
}

int sumof(const int a[], int n) {
	int sum = 0;
	printf("func sizeof: %d\n", sizeof(a));
	// 두 sizeof함수의 결과값의 차이는 무엇인가
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}

double aveof(const int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	int answer = (double)sum / n;
	return answer;
}

int main() {
	int a[] = { 6,4,5,2,8,9 };
	printf("main sizeof: %d\n", sizeof(a));
	printf("%d\n", minof(a, sizeof(a) / sizeof(*a)));
	printf("%d\n", sumof(a, sizeof(a) / sizeof(*a)));
	printf("%2.1f\n", aveof(a, sizeof(a) / sizeof(*a)));
}