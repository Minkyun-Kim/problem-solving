#include <cstdio>
using namespace std;

int n;
int maxi = -2100000000;
int mini = 2100000000;
int oper[10];
int num[11];
int check[10];

void calc(int plus, int minus, int mul, int div, int index, int temp) {
	if (index == n) {
		if (temp > maxi) maxi = temp;
		if (temp < mini) mini = temp;
		return;
	}
	if (plus > 0) {
		int temp_result = temp;
		temp_result += num[index];
		calc(plus - 1, minus, mul, div, index + 1, temp_result);
	}
	if (minus > 0) {
		int temp_result = temp;
		temp_result -= num[index];
		calc(plus, minus-1, mul, div, index + 1, temp_result);
	}
	if (mul > 0) {
		int temp_result = temp;
		temp_result *= num[index];
		calc(plus, minus, mul - 1, div, index + 1, temp_result);
	}
	if (div > 0) {
		int temp_result = temp;
		temp_result /= num[index];
		calc(plus, minus, mul, div-1, index + 1, temp_result);
	}
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &oper[i]);
	}
	calc(oper[0], oper[1], oper[2], oper[3], 1, num[0]);
	printf("%d\n%d\n", maxi, mini);
	return 0;
}
