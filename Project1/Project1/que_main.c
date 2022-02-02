#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"circle_que.h"

int main() {
	que_a* a;
	int x = 0;
	a = malloc(sizeof(que_a));
	initialize(a, 10);

	for (int i = 0; i < 20; i++) {
		if (enque(a, i)) {
			printf("enque %d success\n", i);
		}
		else {
			printf("enque %d failed\n", i);
			break;
		}
	}

	for (int i = 0; i < 5; i++) {
		if (deque(a, &x)) {
			printf("deque %d success\n", x);
		}
		else {
			printf("deque failed\n");
			break;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (enque(a, i)) {
			printf("enque %d success\n", i);
		}
		else {
			printf("enque %d failed\n", i);
			break;
		}
	}

	print_que_a(a);
	printf("\n%d %d\n", size(a), capacity(a));
}