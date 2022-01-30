#include<stdio.h>

void show_search(int a[], int n, int i_a) {
	if (i_a == 0) {
		printf("%3c|", ' ');
		for (int i = 0; i < n; i++) {
			printf("%3d", a[i]);
		}
		printf("\n");
		for (int i = 0; i < 3*(n+1); i++) {
			printf("%c", '-');	
		}
		printf("\n");
	}
	printf("%3c", ' ');
	for (int i = 0; i < n; i++) {
		if (a[i] == a[i_a]) {
			printf("%3c", '*');
		}
		else {
			printf("   ");
		}
	}

	printf("\n%3d|", i_a);
	for (int i = 0; i < n; i++) {
		printf("%3d", i);
	}
	printf("\n");
}

int linear_search(int a[], int n) {
	for (int i = 0; i < n; i++) {
		show_search(a, n, i);
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
		printf("\na[%d]", i);
	}
}