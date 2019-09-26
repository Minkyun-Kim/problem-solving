#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

bool check[29][29];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
double probability[4];
int n;
double ans;

void dfs(int x, int y, double prob, int cnt) {
	if (cnt == 0) {
		ans += prob;
		return;
	}
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!check[nx][ny]) {
			dfs(nx, ny, prob * probability[i], cnt - 1);
		}
	}
	check[x][y] = false;
}

int main() {
	cin >> n;
	for (int i = 0; i < 4; i++) {
		int temp;
		cin >> temp;
		probability[i] = (double)temp / 100.0;
	}
	dfs(14, 14, 1, n);
	cout << fixed;
	cout << setprecision(10) << ans << '\n';

}
