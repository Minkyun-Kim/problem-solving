#include <iostream>
#include <queue>
using namespace std;

int t, boardLength;
bool visited[300][300];
int curX, curY;
int desX, desY;
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };


bool isRange(int x, int y) {
	if (x >= 0 && x < boardLength && y >= 0 && y < boardLength)
		return true;
	return false;
}

void init() {
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			visited[i][j] = false;
		}
	}
}

int bfs() {
	if (curX == desX && curY == desY)
		return 0;
	queue<pair<int, int>> q;
	q.push({ curX, curY });
	visited[curX][curY] = true;
	int moveCnt = 1;
	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (isRange(nx, ny) && !visited[nx][ny]) {
					if (nx == desX && ny == desY)
						return moveCnt;
					q.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}
		}
		moveCnt++;
	}
}

int main() {
	cin >> t;
	while (t--) {
		init();
		cin >> boardLength;
		cin >> curX >> curY>>desX >> desY;
		cout << bfs() << '\n';
	}

}
