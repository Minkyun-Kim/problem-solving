#include <iostream>
#include <cmath>
using namespace std;

int x, y, t;
int ans = 0;

int main() {
	cin >> t;
	while (t--) {
		cin >> x >> y;
		int dist = y - x;
		long long i;
		for (i = 1; i * i <= dist; i++);
		i--;
		dist -= i * i;
		cout << 2 * i - 1 + ceil((double)dist / i) << '\n';
	}

}
