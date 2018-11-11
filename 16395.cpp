#include <iostream>
using namespace std;

int pascal(int n, int k) {
	if (k == n || k == 1)
		return 1;
	return pascal(n - 1, k) + pascal(n - 1, k - 1);
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << pascal(n, k) << '\n';
}
