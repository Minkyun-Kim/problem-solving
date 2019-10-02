#include <iostream>
using namespace std;

int rgb[3][1001];
int dp[3][1001];
int n;

int _min(int a, int b) {
	return a > b ? b : a;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> rgb[j][i];
		}
	}
	for (int i = 1; i <= n; i++) {
		dp[0][i] = _min(dp[1][i - 1], dp[2][i - 1]) + rgb[0][i];
		dp[1][i] = _min(dp[0][i - 1], dp[2][i - 1]) + rgb[1][i];
		dp[2][i] = _min(dp[0][i - 1], dp[1][i - 1]) + rgb[2][i];
	}
	cout << _min(_min(dp[0][n], dp[1][n]), dp[2][n]) << '\n';


}
