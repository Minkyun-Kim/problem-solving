#include <iostream>
using namespace std;

int arr[500][500];
int dp[500][500];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] += dp[i - 1][j] + arr[i][j];
			}
			else if (j == i) {
				dp[i][j] += dp[i - 1][j - 1]+ arr[i][j];
			}
			else {
				if (dp[i - 1][j - 1] > dp[i - 1][j])
					dp[i][j] += dp[i - 1][j - 1] + arr[i][j];
				else
					dp[i][j] = dp[i - 1][j] + arr[i][j];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < dp[n - 1][i])
			ans = dp[n - 1][i];
	}
	cout << ans << '\n';


}
