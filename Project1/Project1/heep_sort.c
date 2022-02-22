#include<stdio.h>
#include<math.h>

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void print_heap(int* a, int m) {
	int c = 0;
	int k = 0;
	for (int i = 0; i < m; i = 2*i + 1) {
		k++;
	}

	for (int i = 0; i < m; i++) {
		printf("%2d", a[i]);
		for (int s = (int)pow(2, k); s > 0; s--) {
			printf("%2c", ' ');
		}
		if (i == c) {
			printf("\n");
			c = 2*c + 2;
			for (int s = (int)pow(1.5, k); s > 0; s--) {
				printf("%2c", ' ');
			}
			k--;
		}
	}
}

int heep_sort(int* a, int m, int n) {
	if (n == -1) {
		return;
	}
	heep_sort(a, m, L_child_node(m, n));
	heep_sort(a, m, R_child_node(m, n));
	int parent = parent_node(m, n);
	if (parent == -1) {
		return a[n];
	}
	if (a[n] < a[parent]) {
		swap(a + n, a + parent);
		heep_sort(a, m, L_child_node(m, n));
		heep_sort(a, m, R_child_node(m, n));
	}
	print_heap(a, m);
	return 0;
}
int L_child_node(int m, int n) {
	if (m > 2 * n + 1)
		return 2 * n + 1;
	else 
		return -1;
}
int R_child_node(int m, int n) {
	if (m > 2 * n + 2) 
		return 2 * n + 2;
	else
		return -1;
}
int parent_node(int m, int n) {
	if (n == 0) 
		return -1;
	else
		return (n - 1) / 2;
}

int down_heep(int* a, int m) {
	int k = *a;
	*a = *(a + m - 1);
	int n = 0;
	while (n != -1) {
		if (a[n] > a[L_child_node(m, n)] && L_child_node(m,n) != -1) {
			swap(a + n, a + L_child_node(m, n));
			n = L_child_node(m, n);
		}
		else if (a[n] > a[R_child_node(m, n)] && R_child_node(m, n) != -1) {
			swap(a + n, a + R_child_node(m, n));
			n = R_child_node(m, n);
		}
		else {
			break;
		}
	}
	return k;
}

void downheap2(int* a, int left, int right) {
	int temp = a[left];
	int child;
	int parent;
	for (parent = left; parent < (right + 1)/2; parent = child) {
		int cl = 2 * parent + 1;
		int cr = cl + 1;
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl; 
		if (temp >= a[child])
			break;
		else
			a[parent] = a[child];
	}
	a[parent] = temp;
}

void heapsort2(int a[], int n) {
	int i;
	for (i = (n - 1 / 2); i >= 0; i--) {
		downheap2(a, i, n - 1);
	}
	for (i = n - 1; i > 0; i--) {
		swap(a, a + i);
		downheap2(a, 0, i - 1);
	}
}

int main() {
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	heapsort2(a, 10);
	print_heap(a, 10);
	/*printf("%d\n", down_heep(a, 10));
	printf("%d\n", down_heep(a, 9));
	printf("%d\n", down_heep(a, 8));
	print_heap(a, 8);*/
}