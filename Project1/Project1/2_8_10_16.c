#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int make_int(char* c, int a) {
	int len = _msize(c) / sizeof(*c);// ÀÚ¸´¼ö
	int answer = 0;
	for (int i = len-1; i >= 0; i--) {
		answer += ( * (c + i)-48) * a;
		a *= a;
	}
	return answer;
}

int find_len(int origin, int n) {
	int i = 0;
	while (origin >= 1) {
		origin /= n;
		i++;
	}
	return i;
}

char* card_convr(char* c,int a, int b) {
	char* digit = calloc(36, sizeof(char));
	digit = "0123456789abcdefghijklmnopqrstuvwxyz";
	int origin = make_int(c, a);
	int len = find_len(origin, b);
	char* answer = malloc(sizeof(char) * len + 1);
	for (int i = len - 1; i >= 0; i--) {
		*(answer + i) = digit[origin % b];
		printf("%c\n", *(answer + i));
		origin /= b;
		if (origin < 1) {
			break;
		}
	}
	*(answer + len) = '\0';
	return answer;
}

int main() {
	char a[] = "1000";
	char* b = malloc(sizeof(a)-1);
	strcpy(b, a);
	printf("%s", card_convr(b, 5, 2));
}