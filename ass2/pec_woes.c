#include <stdio.h>

int main() {
	int n;
	int counter = 0;
	scanf("%d", &n);
	int a[100], b[100], c[100], d[100], area[100][100]={0};

	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		scanf("%d", &b[i]);
		scanf("%d", &c[i]);
		scanf("%d", &d[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = a[i]; j < b[i]; j++) {
			for (int k = c[i]; k < d[i]; k++) {
				if (area[j][k] != 1) {
					area[j][k] = 1;
					counter++;
				}
			}
		}
	}

	printf("%d", counter);
	
}