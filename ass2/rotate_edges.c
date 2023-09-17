#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int arr[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int D;
	scanf("%d", &D);
	if (D == 1) {
		printf("%d ", arr[1][0]);
		for (int i = 1; i < n; i++) {
			printf("%d ", arr[0][i - 1]);
		}
		printf("\n");

		for (int i = 1; i < n - 1; i++) {
			printf("%d ", arr[i + 1][0]);
			for (int j = 1; j < n - 1; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("%d \n", arr[i-1][n-1]);
		}

		for (int i = 0; i < n-1; i++) {
			printf("%d ", arr[n-1][i + 1]);
		}
		printf("%d ", arr[n - 2][n-1]);
	}

	if (D == 0) {
		for (int i = 0; i < n - 1; i++) {
			printf("%d ", arr[0][i + 1]);
		}
		printf("%d \n", arr[1][n - 1]);

		for (int i = 1; i < n - 1; i++) {
			printf("%d ", arr[i - 1][0]);
			for (int j = 1; j < n - 1; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("%d \n", arr[i + 1][n - 1]);
		}

		printf("%d ", arr[n-2][0]);
		for (int i = 1; i < n; i++) {
			printf("%d ", arr[n-1][i - 1]);
		}
		printf("\n");
	}

}