#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int x;
	int y;
	int z;
}_pair3;
int n, m, h;
queue<_pair3> q;
int tomato[100][100][100];
int dx[] = { -1, 0, 1, 0, 0, 0 };
int dy[] = { 0, 1, 0, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

int inBoundary(int posX, int posY, int posZ) {
	if (posX >= 0 && posX < n && posY >= 0 && posY < m && posZ >= 0 && posZ < h)
		return true;
	return false;
}

int main() {
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					q.push({ j, k, i });
				}
			}
		}
	}

	while (!q.empty()) {
		_pair3 current = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = current.x + dx[i];
			int ny = current.y + dy[i];
			int nz = current.z + dz[i];
			if (inBoundary(nx, ny, nz) && tomato[nz][nx][ny] == 0) {
				tomato[nz][nx][ny] = tomato[current.z][current.x][current.y] + 1;
				q.push({ nx, ny, nz });
			}
		}
	}
	bool isNotRipe = false;
	int maxDay = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (tomato[i][j][k] == 0) {
					cout << -1 << '\n';
					return 0;
				}
				if (tomato[i][j][k] > maxDay)
					maxDay = tomato[i][j][k];
			}
		}
	}
	cout << maxDay-1 << '\n';

}
