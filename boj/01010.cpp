#include <iostream>
using namespace std;
int arr[1001][1001];

int combi(int n, int k) {
	if (arr[n][k] != 0)
		return arr[n][k];
	if (k == 0 || k == n)
		return 1;
	return (arr[n-1][k] = combi(n - 1, k)) + (arr[n-1][k-1] = combi(n - 1, k - 1));
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << combi(m, n) << '\n';

	}
	return 0;
}
