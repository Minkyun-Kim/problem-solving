#include <iostream>
#include <queue>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int arr[50][50];
bool check[50][50];
int t, m, n, k;

void initCheck() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check[i][j] = false;
			arr[i][j] = 0;
		}
	}
}

void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push({ x, y });
	check[x][y] = true;
	while (!q.empty()) {
		pair<int, int> pr;
		pr = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = pr.first + dx[i];
			int ny = pr.second + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 1 && !check[nx][ny]) {
				check[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int getWormCnt() {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]==1&& !check[i][j]) {
				bfs(i, j);
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	cin >> t;
	while (t--) {
		initCheck();
		cin >> m >> n >> k;
		while (k--) {
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		cout << getWormCnt() << '\n';
	}
}
