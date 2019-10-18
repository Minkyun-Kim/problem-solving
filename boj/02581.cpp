#include <iostream>
using namespace std;

int n, m;
bool arr[10001];

void checkPrime() {
	for (int i = 2; i <= 100; i++) {
		if (!arr[i]) {
			for (int j = i; i * j <= 10000; j++) {
				arr[i * j] = true;
			}
		}
	}
}

int main() {
	cin >> m >> n;
	arr[1] = true;
	checkPrime();
	int _min = 10001;
	int sum = 0;
	for (int i = m; i <= n; i++) {
		if (!arr[i]) {
			if (_min > i) {
				_min = i;
			}
			sum += i;
		}
	}
	if (_min == 10001) {
		cout << -1 << '\n';
	}
	else {
		cout << sum << '\n' << _min << '\n';
	}
}
