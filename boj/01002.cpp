#include <iostream>
using namespace std;

int t, d, x_1, x_2, y_1, y_2, r1, r2;

int _sqrt(int num) {
	return num * num;
}


int main() {
	cin >> t;
	while (t--) {
		cin >> x_1 >> y_1 >> r1 >> x_2 >> y_2 >> r2;
		d = (x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2);
		if (d > _sqrt(r1 + r2)) {
			cout << 0;
		}
		else if (d == _sqrt(r1 + r2)) {
			cout << 1;
		}
		else {
			if (r1 == r2 && x_1 == x_2 && y_1 == y_2) {
				cout << -1;
			}
			else if (d > _sqrt(r1 - r2)) {
				cout << 2;
			}
			else if (d == _sqrt(r1 - r2)) {
				cout << 1;
			}
			else if (d < _sqrt(r1 - r2)) {
				cout << 0;
			}
		}
		cout << '\n';
	}
}
