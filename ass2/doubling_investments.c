#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;

	for (int i = 0; n!=0; i++) {
		sum += n % 2;
		n /= 2;
	}
	printf("%d", sum);
}