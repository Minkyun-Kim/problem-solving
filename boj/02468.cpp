#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int land[102][102];
int origin[102][102];
bool check[102][102];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int n;
int ans;
int temp;

void _init() {
	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			land[i][j] = origin[i][j];
			check[i][j] = false;
			temp = 0;
		}
	}
}

void spread(int x, int y) {
	queue<pair<int, int> > q;
	q.push({ x, y });
	while (!q.empty()) {
		pair<int, int> pr = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = pr.first + dx[i];
			int ny = pr.second + dy[i];
			if (land[nx][ny] && !check[nx][ny]) {
				q.push({ nx, ny });
				check[nx][ny] = true;
			}
		}
	}

}

void countLand() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (land[i][j] && !check[i][j]) {
				spread(i, j);
				temp++;
			}
		}
	}
}

int main() {
	cin >> n;
	int flag = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> origin[i][j];
			if (origin[i][j] != 1)
				flag = 1;
		}
	}
	if (!flag) {
		cout << 1 << '\n';
		return 0;
	}

	for (int i = 1; i <= 100; i++) {
		_init();
		for (int j = 1; j <= 100; j++) {
			for (int k = 1; k <= 100; k++) {
				if (land[j][k] <= i)
					land[j][k] = 0;
			}
		}
		countLand();
		ans = ans < temp ? temp : ans;
	}
	cout << ans << '\n';
}
