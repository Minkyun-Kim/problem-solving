#include <cstdio>


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = n-i; j >0; j--) {
			printf(" ");
		}
		for (int k=i; k > 0; k--) {
			printf("*");
		}
		printf("\n");
	}
}