#include<stdio.h>
#include<stdlib.h>

void draw_div(int a, int b) {
	printf("%2d|%6d --- %d", b, a, a%b);
	printf("\n----------\n");
	if (a / b == 0) {
		printf("%8d", 0);
	}
}

int expect_len(int a, int b) {
	int i = 0;
	while (a > 0) {
		a /= b;
		i++;
	}
	return i;
}

char* card_conv(int a, int n) {
	printf("10진수를 기수 변환합니다.\n 변환하는 음이 아닌 정수: %d\n 변환 진수: %d\n", a, n);
	int len = expect_len(a, n);
	char* digit = "0123456789abcdefghijklmnopqrstuvwxyz";
	char* r = malloc(sizeof(char) * len+1);
	int i = len-1;
	while (a > 0) {
		draw_div(a, n);
		*(r + i) = digit[a % n];
		a /= n;
		i--;
	}
	r[len] = '\0';
	return r;
}

int main() {
	printf("\n%s", card_conv(58, 2));
}