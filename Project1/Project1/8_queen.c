#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

void print_set(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%2d", *(a + i));
	}
	printf("\n");
}

bool set(int j, int *pos, int *flag, int* flag_a, int* flag_b) {
	for (int i = 0; i < 8; i++) {
		if (j == 8) {
			printf("break");
			print_set(pos, 8);
			break;
		}
		if (!flag[i] && !flag_a[i + j] && !flag_b[i - j + 7]) {
			pos[j] = i;
			flag[i] = flag_a[i + j] = flag_b[i - j + 7] = 1;
			set(j+1, pos, flag, flag_a, flag_b);
			flag[i] = flag_a[i + j] = flag_b[i - j + 7] = 0;
		}
	}
	if (j == 7) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int j = 0;
	int pos[8] = { 0 };
	int flag[8] = { 0 };
	int flag_a[15] = { 0 };
	int flag_b[15] = { 0 };
	set(0, pos, flag, flag_a, flag_b);
}