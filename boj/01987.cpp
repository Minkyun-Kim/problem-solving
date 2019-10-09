#include <iostream>
using namespace std;

int r, c;
char arr[20][20];
bool alpha[26];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int ans = 0;

void dfs(int x, int y, int dist) {
	if (x < 0 || x >= r || y < 0 || y >= c) {
		if (ans < dist - 1)
			ans = dist - 1;
		return;
	}
	if (alpha[arr[x][y] - 'A'] == true) {
		if (ans < dist - 1)
			ans = dist - 1;
		return;
	}
	alpha[arr[x][y] - 'A'] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		dfs(nx, ny, dist + 1);
	}
	alpha[arr[x][y] - 'A'] = false;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 0, 1);

	cout << ans << '\n';
}
