#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int visited[4][100][100];
int n;

typedef struct Node {
	int x;
	int y;
	int dir;
}Node;

bool isInRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n)
		return true;
	return false;
}

int solution(vector<vector<int>> board) {
	n = board.size();
	int answer = 0;
	queue<Node> q;
	q.push({ 0, 0, 1 });
	visited[1][0][0] = true;
	visited[3][0][1] = true;
	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			int x = q.front().x;
			int y = q.front().y;
			int dir = q.front().dir;
			q.pop();
			int xx = x + dx[dir];
			int yy = y + dy[dir];
			if ((x == n - 1 && y == n - 1) || (xx == n - 1 && yy == n - 1))
				return answer;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nxx = xx + dx[i];
				int nyy = yy + dy[i];
				if (!isInRange(nx, ny) || !isInRange(nxx, nyy))
					continue;
				if (visited[dir][nx][ny] || visited[(dir + 2) % 4][nxx][nyy])
					continue;
				if (board[nx][ny] || board[nxx][nyy])
					continue;
				visited[dir][nx][ny] = true;
				visited[(dir + 2) % 4][nxx][nyy] = true;
				q.push({ nx, ny, dir });
			}

			for (int i = 0; i < 2; i++) {
				int nxx = x + dx[(dir + i * 2 + 1) % 4];
				int nyy = y + dy[(dir + i * 2 + 1) % 4];
				int ndir = (dir + i * 2 + 1) % 4;
				if (!isInRange(nxx, nyy))
					continue;
				if (visited[ndir][x][y] || visited[(ndir + 2) % 4][nxx][nyy])
					continue;
				if (board[nxx][nyy])
					continue;
				if (dir == 1 || dir == 3) {
					if (board[nxx][yy])
						continue;
				}
				else {
					if (board[xx][nyy])
						continue;
				}
				visited[ndir][x][y] = true;
				visited[(ndir + 2) % 4][nxx][nyy] = true;
				q.push({ x, y, ndir });
			}
			swap(x, xx);
			swap(y, yy);
			dir = (dir + 2) % 4;
			for (int i = 0; i < 2; i++) {
				int nxx = x + dx[(dir + i * 2 + 1) % 4];
				int nyy = y + dy[(dir + i * 2 + 1) % 4];
				int ndir = (dir + i * 2 + 1) % 4;
				if (!isInRange(nxx, nyy))
					continue;
				if (visited[ndir][x][y] || visited[(ndir + 2) % 4][nxx][nyy])
					continue;
				if (board[nxx][nyy])
					continue;
				if (dir == 1 || dir == 3) {
					if (board[nxx][yy])
						continue;
				}
				else {
					if (board[xx][nyy])
						continue;
				}
				visited[ndir][x][y] = true;
				visited[(ndir + 2) % 4][nxx][nyy] = true;
				q.push({ x, y, ndir });
			}
		}
		answer++;
	}
	return answer;
}
