#include <iostream>
using namespace std;

int n, m;
int arr[500][500];
int ans;
int check[500][500];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool boundary(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return false;
	return true;
}

int dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) {
		ans++;
		return 1;
	}

	if (check[x][y]!=-1) return check[x][y];
	check[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(boundary(nx, ny) && arr[x][y] > arr[nx][ny])
			check[x][y] += dfs(nx, ny);
	}
	return check[x][y];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			check[i][j] = -1;
		}
	}

	dfs(0, 0);
	cout << check[0][0] << '\n';

}
