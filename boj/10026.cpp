#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n;
string picture[100];
bool visited[100][100];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool isInRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n)
		return true;
	return false;
}

void bfs(int posX, int posY) {
	char color = picture[posX][posY];
	queue<pair<int, int>> q;
	q.push({ posX, posY });
	visited[posX][posY] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isInRange(nx, ny) && !visited[nx][ny] && picture[nx][ny] == color) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> picture[i];
	}
	int normal = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j])
				continue;
			bfs(i, j);
			normal++;
		}
	}
	int colorPills = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
			if (picture[i][j] == 'R')
				picture[i][j] = 'G';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j])
				continue;
			bfs(i, j);
			colorPills++;
		}
	}
	cout << normal << ' ' << colorPills << '\n';
}
