#include <iostream>

using namespace std;

int main() {
	int n, five = 0, three = 0;
	cin >> n;
	five = n / 5;
	while (1) {
		if (n == five * 5) {
			cout << five << endl;
			return 0;
		}
		else {
			for (; five * 5 < n; five--) {
				if (five < 0) {
					cout << "-1" << endl;
					return 0;
				}
				if ((n - (five * 5))%3 == 0) {
					three = (n - (five * 5)) / 3;
					break;
				}
				
			}
			break;
		}
	}
	cout << five + three << endl;
}