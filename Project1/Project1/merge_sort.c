#include"merge_sort.h"
int* merge_sort(int* a, int m) {
	int* b = a + m / 2;
	int* c = (int*)malloc(sizeof(int) * m);
	if (m == 1) {
		*c = *a;
		return c;
	}
	else if (m < 1) {
		return NULL;
	}
	int* p = merge_sort(a, m / 2);
	int* q = merge_sort(b, m - m / 2);
	int pi = 0;
	int qi = 0;
	int i = 0;

	while (pi < m/2 && qi < m-m/2) {
		if (*(p + pi) >= *(q + qi)) {
			c[i++] = q[qi++];
			continue;
		}
		else{
			c[i++] = p[pi++];
			continue;
		}
	}

	while (pi < m/2) {
		c[i++] = p[pi++];
	}
	while (qi < m-m/2) {
		c[i++] = q[qi++];
	}
	free(p);
	free(q);
	return c;
}

void merge_sort2(int a[], int left, int right, int* buff) {
	if (left < right) {
		int center = (left + right) / 2;
		merge_sort2(a, left, center, buff);
		merge_sort2(a, center + 1, right, buff);
		int p = 0;
		int i = 0;
		int j = 0;
		int k = left;
		for (i = left; i <= center; i++) {
			buff[p++] = *(a + i);
		}
		while (i <= right && j < p)
			a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
		while (j < p)
			a[k++] = buff[j++];		
	}
}

bool mergesort2(int* a, int n) {
	static int* buff;
	if ((buff = calloc(n, sizeof(int))) == NULL) {
		return false;
	}
	merge_sort2(a, 0, n - 1, buff);
	free(buff);
	return true;
}

void print_ary(int* a, int m) {
	for (int i = 0; i < m; i++) {
		printf("%2d", a[i]);
	}
	printf("\n");
}

int main() {
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	mergesort2(a, 10);
	print_ary(a, 10);
}

//���� �ɸ� ���� : i�� c�͸� ���õ� ������ �ذ� ���
//���� �ɸ� ���� : pi, qi�� ó������ ���ؾ� �Ѵٴ� ���� �����ϰ� ���� ��� �� ���� ����.
//���� �ɸ� ���� : m�� 1�� ���� ��� m - m / 2�� ���� ������ ���� �� �ִٴ� ���� ������.
//�ߴ��� Ʈ���� ����: ���� ������ �Ҵ�� ������ �� ū ������ �Ҵ��Ͽ� �ʱ�ȭ �� �� free�� �� �߻���
