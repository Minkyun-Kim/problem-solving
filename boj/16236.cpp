#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[20][20];
int visited[20][20];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int ans;
int x, y, dist;

struct fish {
	int x;
	int y;
	int time;
	int eat;
	int size;
};
struct pos {
	int x;
	int y;
	int dist;
};

bool comp(pos p1, pos p2) {
	if (p1.dist > p2.dist)
		return false;
	else if(p1.dist == p2.dist){
		if (p1.x < p2.x)
			return true;
		else if (p1.x == p2.x) {
			if (p1.y < p2.y)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else {
		return true;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fish fsh = {.x = 0, .y = 0, .time = 0, .eat = 0, .size = 2};
	pos posi;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				arr[i][j] = 0;
				fsh = { i, j, 0, 0, 2 };
				fsh.x = i;
				fsh.y = j;
			}
		}
	}
	queue<pos> q;
	vector<pos> v;
	while (1) {
		posi = {.x = fsh.x, .y = fsh.y, .dist = 0};
		q.push(posi);
		visited[fsh.x][fsh.y] = 1;
		while (!q.empty()) {
			pos cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				//바다 범위를 넘어서는 경우
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;
				if (visited[nx][ny])
					continue;
				if (arr[nx][ny] > fsh.size)
					continue;
				else if (arr[nx][ny] == 0 || arr[nx][ny] == fsh.size) {
					q.push({.x = nx, .y = ny, .dist = cur.dist+1});
					visited[nx][ny] = 1;
				}
				else {
					posi = {.x = nx, .y = ny, .dist = cur.dist+1};
					v.push_back(posi);
					visited[nx][ny] = 1;
				}
			}
		}
		if (v.size() == 0) 
			break;
		sort(v.begin(), v.end(), comp);
		fsh.x = v[0].x;
		fsh.y = v[0].y;
		arr[fsh.x][fsh.y] = 0;
		fsh.time += v[0].dist;
		fsh.eat++;
		if (fsh.eat == fsh.size) {
			fsh.size++;
			fsh.eat = 0;
		}
		memset(visited, 0, sizeof(visited));
		v.clear();

	}

	cout << fsh.time << '\n';
	return 0;
}

