#include<stdio.h>

void show_search(int a[], int pl, int pr, int pc, int i_a, int n) {
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

	printf("%3c|", ' ');
	for (int i = 0; i < n; i++) {
		if (i == pl) {
			printf("%3s", "<-");
		}
		else if (i == pr) {
			printf("%3s", "->");
		}
		else if (i == pc) {
			printf("%3c", '+');
		}
		else {
			printf("%3c", ' ');
		}
	}
	printf("\n");
}

int binary_search(int a[], int n, int key) {
	int pl = 0;
	int pr = n-1;
	int pc = (pl + pr) / 2;
	int i = 0;

	while (pl <= pr) {
		show_search(a, pl, pr, pc, i, n);
		if (a[pc] == key) {
			for (int i = pc; a[i - 1] == key; i--) {
				pc--;
			}
			return pc;
		}
		else if (a[pc] < key) {
			pl = pc + 1;
			pc = (pr + pl) / 2;
		}
		else {
			pr = pc - 1;
			pc = (pr + pl) / 2;
		}
		i++;
	}
	return -1;
}

int main() {
	int a[] = { 1,2,3,5,5,6,7,8,9 };
	int k = binary_search(a, sizeof(a)/sizeof(*a), 7);
	if (k == -1) {
		printf("fail");
	}
	else {
		printf("a[%d]", k);
	}
}