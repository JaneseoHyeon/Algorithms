#include <cstdio>
#include <cstdlib>
int U[8];

void merge(int low, int mid, int high, int S[]) {
	int i, j, k, l;
	i = low; j = mid + 1; k = low;
	while (i <= mid && j <= high) {
		if (S[i] < S[j])
			U[k++] = S[i++];
		else 
			U[k++] = S[j++];
	}
	if (i > mid) {
		for (l = j; l <= high; l++)
			U[k++] = S[l];
	}
	else {
		for (l = i; l <= mid; l++)
			U[k++] = S[l];
	}
	for (l = low; l <= high; l++) {
		S[l] = U[l];
		printf("%d ", S[l]);
	}
	printf("\n");
}

void mergesort(int low, int high, int S[]) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		for (int i = low; i <= mid; i++) {
			printf("%d ", S[i]);
		}
		printf("\n");
		mergesort(low, mid, S);

		for (int i = mid + 1; i <= high; i++) {
			printf("%d ", S[i]);
		}
		printf("\n");
		mergesort(mid + 1, high, S);

		merge(low, mid, high, S);
	}
} 

void main() {
	int S[8] = { 27, 10, 12, 20, 25, 13, 15, 22 };
	for (int i = 0; i < 8; i++)
		printf("%d ", S[i]);
	printf("\n");

	mergesort(0, 7, S);
	
	system("PAUSE");
}