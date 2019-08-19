#include <iostream>
using namespace std;

int combi(int n, int k) {
	if (k == 0 || k == n)
		return 1;
	return combi(n - 1, k) + combi(n - 1, k - 1);
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << combi(n, k) << '\n';
	return 0;
}
