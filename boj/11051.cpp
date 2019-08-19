#include <iostream>
using namespace std;
int arr[1001][1001];

int combi(int n, int k) {
	if (arr[n][k] != 0)
		return arr[n][k];
	if (k == 0 || k == n)
		return 1;
	return ((arr[n-1][k] = combi(n - 1, k))%10007 + (arr[n-1][k-1] = combi(n - 1, k - 1))%10007)%10007;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << combi(n, k) << '\n';
	return 0;
}
