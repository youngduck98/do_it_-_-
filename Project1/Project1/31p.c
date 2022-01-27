#include<stdio.h>

int sum_g(int n) {
	int sum = 0;
	sum = (1 + n) * (n / 2);
	if (n % 2 == 1) {
		sum += n / 2 + 1;
	}
	return sum;
}

int sum_i(int a, int b) {
	int sum = 0;
	int num = b - a + 1;
	sum = (a + b) * (num / 2);
	if (num % 2 == 1) {
		sum += (a + b + 1) / 2;
	}
	return sum;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", sum_i(a,b));
}