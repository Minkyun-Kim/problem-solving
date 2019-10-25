#include <iostream>
using namespace std;

int n, m;
int sum = 0, _min = 10001;

int main() {
	cin >> n >> m;

	for (int i = 1; i * i <= m; i++) {
		if (i * i >= n) {
			sum += i * i;
			_min = _min > i* i ? i * i : _min;
		}
	}
	if (sum != 0) {
		cout << sum << '\n';
		cout << _min << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	
	
}
