#include<stdio.h>
#include"Bitset.h"
#include<stdlib.h>
#include<time.h>
#include"str.h"

int main() {
	char* origin = "what are you doing?";
	char* s = "abcabc";
	kmp_match_str(origin, s);
}