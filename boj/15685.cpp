#include <cstdio>
#include <vector>
using namespace std;

int n;
int drag[20][4];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
bool map[101][101];
void curve(int dragNum, vector<vector<int> > &v) {
	int index = v[dragNum].size();
	for (int i = index-1; i >= 0; i--) {
		v[dragNum].push_back((v[dragNum][i] + 1) % 4);
	}
}

int main() {
	scanf("%d", &n);
	vector<vector<int> > v(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &drag[i][j]);
		}
		v[i].push_back(drag[i][2]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < drag[i][3]; j++) {
			curve(i, v);
		}
	}
	for (int i = 0; i < n; i++) {
		int x = drag[i][0];
		int y = drag[i][1];
		if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
			map[x][y] = true;
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == 0) {
				x += dx[0];
				y += dy[0];
			}
			else if (v[i][j] == 1) {
				x += dx[1];
				y += dy[1];
			}
			else if (v[i][j] == 2) {
				x += dx[2];
				y += dy[2];
			}
			else {
				x += dx[3];
				y += dy[3];
			}
			if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
				map[x][y] = true;
			
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j + 1] && map[i + 1][j] && map[i][j + 1])
				ans++;
		}
	}
	printf("%d\n", ans);
}
