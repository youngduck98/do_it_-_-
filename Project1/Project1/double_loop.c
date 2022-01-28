#include<stdio.h>

void  multiple_cell() {
	for (int i = 0; i <= 9;i++) {
		if (i == 0) {
			printf("%3s|", "");
		}
		else {
			printf("%3d", i);
		}
	}
	printf("\n---+--------------------------------------------------------------------------------\n");

	for (int line = 1; line <= 9; line++) {
		for (int cal = 0; cal <= 9; cal++) {
			if (cal == 0) {
				printf("%3d|", line);
			}
			else {
				printf("%3d", line * cal);
			}
		}
		printf("\n");
	}
}

void plus_cell() {
	for (int i = 0; i <= 9; i++) {
		if (i == 0) {
			printf("%3s|", "");
		}
		else {
			printf("%3d", i);
		}
	}
	printf("\n---+--------------------------------------------------------------------------------\n");

	for (int line = 1; line <= 9; line++) {
		for (int cal = 0; cal <= 9; cal++) {
			if (cal == 0) {
				printf("%3d|", line);
			}
			else {
				printf("%3d", line + cal);
			}
		}
		printf("\n");
	}
}

void make_square(int n) {
	for (int line = 0; line < n; line++) {
		for (int cal = 0; cal < n; cal++) {
			printf("*");
		}
		printf("\n");
	}
}

void make_rec(int a, int b) {
	for (int line = 0; line < a; line++) {
		for (int cal = 0; cal < b; cal++) {
			printf("*");
		}
		printf("\n");
	}
}

void triangleLB(int n) {
	for (int line = 0; line < n; line++) {
		for (int cal = 0; cal < n; cal++) {
			if (cal > line) {
				break;
			}
			printf("*");
		}
		printf("\n");
	}
}

void triangleLU(int n) {
	for (int line = 0; line < n; line++) {
		for (int cal = 0; cal < n; cal++) {
			if (cal >= n - line) {
				break;
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
}

void triangleRB(int n) {
	for (int line = 0; line < n; line++) {
		for (int cal = 0; cal < n; cal++) {
			if (cal < n - line - 1) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
}

void triangleRU(int n) {
	for (int line = 0; line < n; line++) {
		for (int cal = 0; cal < n; cal++) {
			if (cal <= line-1) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
}


int main() {
	multiple_cell();
	plus_cell();
	make_square(4);
	make_rec(3, 5);
	triangleLB(5);
	triangleLU(5);
	triangleRB(5);
	triangleRU(5);
}