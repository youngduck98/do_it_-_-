#include "Bitset.h"
#include<stdio.h>

bool isMember(Bitset* s, int n)
{
	if (*s & setof(n))
		return true;
	else
		return false;
}

void add(Bitset* s, int n)
{
	if (isMember(s, n))
		return;
	else
		*s = *s | setof(n);
	printf("%3d\n", n);
}

void Remove(Bitset* s, int n)
{
	if (isMember(s, n)) {
		*s = *s ^ setof(n);
	}
}

int size(Bitset* s)
{
	int size = 0;
	for (int i = 0; i < 32; i++) {
		if (*s & setof(i)) {
			size++;
		}
	}
	return size;
}

void print(Bitset* s)
{
	printf("set: ");
	for (int i = 0; i < 32; i++) {
		if (*s & setof(i)) {
			printf("%2d, ", i);
		}
	}
	printf("\n");
}


