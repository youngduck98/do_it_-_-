#include<stdio.h>

int print_digit(int a) {
	int i = 0;
	do {
		i++;
		a /= 10;
	} while (a >= 1);
	return i;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("ÀÚ¸´¼ö: %d", print_digit(n));
}