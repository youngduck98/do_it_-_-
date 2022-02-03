#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int uclid_gcf(int x, int y) {
	if (y == 0) {
		return x;
	}
	return uclid_gcf(y, x % y);
}

int main() {
	printf("%d", uclid_gcf(25, 15));
}