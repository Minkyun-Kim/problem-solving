#include <iostream>
using namespace std;

int c(int n) {
	if (n % 2 == 0)
		return n / 2;
	else
		return 3 * n + 1;
}

int main() {
	int n;
	cin >> n;
	int i = 1;
	do {
		n = c(n);
		i++;
	} while (!(n == 1));
	cout << i << endl;
}


