#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"circle_que.h"

bool initialize(que_a* s, int max) {
	s->que = malloc(sizeof(int) * max);
	s->max = max;
	s->num = 0;
	s->sq = 0;
	s->eq = 0;
}

bool enque(que_a* s, int x) {
	if (isfull(s)) {
		return false;
	}
	else {
		*(s->que + s->eq) = x;
		s->num++;
	}

	if (s->eq < s->max - 1) {
		s->eq++;
	}
	else {
		s->eq = 0;
	}
	return true;
}

bool deque(que_a* s, int* x) {
	if (isempty(s)) {
		return false;
	}
	else {
		*x = *(s->que + s->sq);
		s->num--;
	}

	if (s->sq > s->max - 1) {
		s->sq = 0;
	}
	else {
		s->sq++;
	}
	return true;
}

bool peek(que_a* s, int* x) {
	if (isempty(s)) {
		return false;
	}
	else {
		*x = *(s->que + s->sq);
		return true;
	}
}

bool claer(que_a* s) {
	if (isempty(s)) {
		printf("the que is empty");
		return false;
	}
	else {
		s->sq = 0;
		s->eq = 0;
		for (int i = 0; i < s->max; i++) {
			*(s->que + i) = 0;
		}
	}
}

bool isempty(que_a* s) {
	if (s->num == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool isfull(que_a* s) {
	if (s->num == s->max) {
		return true;
	}
	else {
		return false;
	}
}

int capacity(que_a* s) {
	return s->max;
}

int size(que_a* s) {
	return s->num;
}

void print_que_a(que_a* s) {
	int k = 0;
	for (int i = 0; i < s->num; i++) {
		printf("%d ", *(s->que + s->sq + k));
		if (s->sq + k < s->max - 1) {
			k++;
		}
		else {
			k = -(s->sq);
		}
	}
}
