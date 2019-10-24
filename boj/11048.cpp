#include <iostream>
using namespace std;

int n, m;
int maze[1001][1001];
int candyCount[1001][1001];

int getMaximumOfThree(int a, int b, int c) {
	return a > b ? (a > c ? a : (b > c ? b : c)) : (b > c ? b : (a > c ? a : c));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> maze[i][j];
			candyCount[i][j] += maze[i][j];
			candyCount[i][j] += getMaximumOfThree(candyCount[i - 1][j - 1], candyCount[i - 1][j], candyCount[i][j - 1]);
		}
	}
	cout << candyCount[n][m] << '\n';
	
	
}
