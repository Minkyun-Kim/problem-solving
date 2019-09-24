#include <iostream>
using namespace std;

int main() {
	long long x, y, z;
	cin >> x >> y;
	z = y * 100 / x;
	if (z >= 99) {
		cout << -1 << '\n';
		return 0;
	}
	int start = 0, end = 1000000000;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if ((y + mid) * 100 / (x + mid) > z) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << start << '\n';


}
