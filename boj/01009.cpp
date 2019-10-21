#include <iostream>
using namespace std;

int t, a, b;

int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int data = 1;
		while (b--) {
			data *= a;
			data %= 10;
		}
		if (data)
			cout << data << '\n';
		else
			cout << 10 << '\n';

	}

}
