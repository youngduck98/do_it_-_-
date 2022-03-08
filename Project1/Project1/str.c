#include "str.h"
#include"ary.h"
#include<string.h>
#include<stdlib.h>

int str_chr(char* s, char c)
{
	int len = str_len(s);
	for (int i = 0; i < len; i++) {
		if (*(s+i) == c) {
			return i;
		}
	}
	return -1;
}

int str_len(char* s) {
	char* p = s;
	while (*p) {
		p++;
	}
	return p - s;
}

int str_rchr(char* s, char c)
{
	for (int i = strlen(s) - 1; i >= 0; i--) {
		if (*(s + i) == c)
			return i;
	}
	return -1;
}

int str_cmp(char* s1, char* s2)
{
	int len = strlen(s1);
	for (int i = 0; i < len && *s1 == *s2; i++, s1++, s2++);
	
	if (*s1 == *s2 && *s2 == '\0') {
		//*s1==*s2=='\0'이라 하면 결과가 나오는 기현상을 볼 수 있다.
		//예를 들어 *s1==*s2가 flase라면 0으로 취급 되는데 뒤의 '\0'역시 0으로 취급 되기에
		//0==0이 되어 true로 인식한다.
		printf("%c %c\n", *s1, *s2);
		return 0;
	}
	else if (*s1 > *s2)
		return 1;
	else
		return -1;
}

int str_cmpic(char* s1, char* s2)
{
	while (*s1 == *s2 || *s1 + 32 == *s2 || *s1 == *s2 + 32) {
		if (*s1 == '\0')
			return 0;
		s1++; s2++;
	}
	if (*s1 > *s2)
		return 1;
	else
		return -1;
}

int strn_cmp(char* s1, char* s2, int n)
{
	for (int i = 0; i < n - 1 && *s1 == *s2 && *s1 != '\0' && *s2 != '\0'; i++, s1++, s2++);
	if (*s1 == *s2)
		return 0;
	else if (*s1 > *s2)
		return 1;
	else
		return -1;
}

int strn_cmpic(char* s1, char* s2, int n)
{
	for (int i = 0; i < n-1; i++, s1++, s2++) {
		if (*s1 != *s2 && *s1 != *s2 + 32 && *s1 + 32 == *s2)
			break;
		if (*s1 == '\0')
			return 0;
	}
	if (*s1 == *s2 || *s1+32 ==*s2||*s1 == *s2+32)
		return 0;
	else if (*s1 > *s2)
		return 1;
	else
		return -1;
}

int bf_match_str(char* origin, char* a)
{
	for (int i = 0; i < strlen(origin); i++) {
		if (*(origin + i) == *a) {
			int key = 0;
			for (int p = 0; p < strlen(a); p++) {
				if (*(origin + i + p) != *(a + p)) {
					break;
				}
				key++;
			}
			if (key == strlen(a)) {
				return i;
			}
		}
	}
	return -1;
}

int kmp_match_str(char* origin, char* search)
{
	int s_len = strlen(search);
	int* pattern_o = malloc(sizeof(int) * s_len);
	int* pattern_s = malloc(sizeof(int) * s_len);
	memset(pattern_o, 0, sizeof(int) * s_len);
	memset(pattern_s, 0, sizeof(int) * s_len);

	for (int i = 1; i < s_len/2; i++) {
		for (int k = i; k < s_len; k++) {
			if (*search == *(search + k)) {
				for (int n = 0; n < i; n++) {
					printf("%c %c\n", *(search + n), *(search + k + n));
					if (*(search + n) != *(search + k + n)) {
						break;
					}
					if (n == i - 1) {
						*(pattern_o + k) = k;
						*(pattern_s + k) = n;
					}
				}
				break;
			}
		}
	}

	print_ary(pattern_o, s_len);
	print_ary(pattern_s, s_len);
	return 0;
}
