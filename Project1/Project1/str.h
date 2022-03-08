#pragma once
#include<stdio.h>
#include<stdbool.h>

#ifndef ___str
#define ___str

int str_chr(char* s, char c);
int str_len(char* s);
int str_rchr(char* s, char c);
int str_cmp(char* s1, char* s2);
int str_cmpic(char* s1, char* s2);
int strn_cmp(char* s1, char* s2, int n);
int strn_cmpic(char* s1, char* s2, int n);
int bf_match_str(char* origin, char* a);
int kmp_match_str(char* origin, char* search);

#endif // !___str
