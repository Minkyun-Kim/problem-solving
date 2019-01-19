#include <iostream>
using namespace std;


static int zero = 0;
static int one = 0;
int fibonacci(int n) {
	if (n == 0) {
		zero++;
		return 0;
	}
	else if (n == 1) {
		one++;
		return 1;
	}
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	int n;
	cin >> n;
	int test;
	while (n--) {
		cin >> test;
		fibonacci(test);
		cout << zero << " " << one << endl;
		zero = 0;
		one = 0;
	}
	return 0;
}