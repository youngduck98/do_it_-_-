#pragma once
#include<stdbool.h>
#ifndef ___Bitset
#define ___Bitset

typedef unsigned long Bitset; //Bitset == unsigned long

#define BitsetNull (Bitset)0
#define BitsetBits 32
#define setof(no) ((Bitset)1 << (no))

bool isMember(Bitset* s, int n);

void add(Bitset* s, int n);

void Remove(Bitset* s, int n);

int size(Bitset* s);

void print(Bitset* s);
#endif // !___Bitset
