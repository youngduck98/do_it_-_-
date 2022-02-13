#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void recur_1(int n) {
	while (n>0) {
		recur_1(n - 1);
		printf("%d\n", n);
		n = n - 2;
	}
}


void recur(int n) {
	if (n > 0) {
		recur(n - 1);
		printf("%d\n", n);
		recur(n - 2);
	}
}

int main() {
	printf("1\n");
	recur(5);
	printf("\n2\n");
	recur(5);
}