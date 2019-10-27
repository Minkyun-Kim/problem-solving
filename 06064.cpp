#include <iostream>
using namespace std;

int t, m, n, x, y;

int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	cin >> t;
	while (t--) {
		cin >> m >> n >> x >> y;
		int maxYear = lcm(m, n);
		int a = x;
		while (a <= maxYear) {
			if ((a-1) % n+1 == y) {
				break;
			}
			a += m;
		}
		if (a <= maxYear) {
			cout << a << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}
	
	
}
