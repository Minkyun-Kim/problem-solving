#include <iostream>
using namespace std;

int arr[100001];
int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = arr[i] + dp[i - 1];
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << '\n';
	}
}
