#include <iostream>
using namespace std;

int main() {


	int f0 = 0, f1 = 1, f2;
	int n;
	cin >> n;
	if (n == 1) {
		cout << f1 << endl;
		return 0;
	}
	else {
		for (int i = 0; i < n - 1; i++) {
			f2 = f0 + f1;
			f0 = f1;
			f1 = f2;

		}
	}
	cout << f2 << endl;

	return 0;
}