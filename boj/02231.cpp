#include <iostream>
using namespace std;

bool isConstructor(int toCheck, int n) {
	int sum = toCheck;
	while (toCheck) {
		sum += toCheck % 10;
		toCheck /= 10;
	}
	if (n == sum) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++ ) {
		if (isConstructor(i, n)) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
}
