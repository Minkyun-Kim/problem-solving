#include <iostream>
using namespace std;

long long arr[1001][1001];

long long combi(int n, int k) {
	if (arr[n][k] != 0)
		return arr[n][k];
	if (k == 0 || k == n)
		return 1;
	arr[n - 1][k] = combi(n - 1, k);
	if (arr[n - 1][k] > 1000000000)
		arr[n - 1][k] = 1000000001;
	arr[n - 1][k - 1] = combi(n - 1, k - 1);
	if (arr[n - 1][k - 1] > 1000000000)
		arr[n - 1][k - 1] = 1000000001;
	return arr[n-1][k] + arr[n-1][k-1];
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	if (combi(n + m, n) < k) {
		cout << -1 << '\n';
		return 0;
	}
	
	int ni = 0;
	for (int i = 1; i <= n+m; i++) {
		if (ni == n) {
			cout << "z";
			continue;
		}
		if (combi(n + m - i, n - ni -1) < k) {
			k -= combi(n + m - i, n - ni - 1);
			cout << "z";
		}
		else {
			cout << "a";
			ni++;
		}
	}
	/*
	int N = n;
	int K = k;
	int index = 1;
	while (index <= n + m) {
		if (k <= arr[n + m - index][N - 1]) {
			cout << "a";
			N--;
		}
		else {
			cout << "z";
			k -= arr[n + m - index][N - 1];
		}
		index++;
	}
	*/
	cout << '\n';
	return 0;
}
