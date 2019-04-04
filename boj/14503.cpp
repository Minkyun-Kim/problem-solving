#include <cstdio> 
using namespace std; 
int room[51][51]; 
int n, m; 
int r, c, d, dir;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int bx[] = { 1, 0, -1, 0 };
int by[] = { 0, -1, 0, 1 };
int ans;

void clean(int turn) {
	if (room[r][c] == 0) {
		room[r][c] = 2;
		ans++;
	}
	if (turn == 5) {
		return;
	}
	int nx, ny;
	if (turn == 4) {
		nx = r + bx[d];
		ny = c + by[d];
		if (room[nx][ny] == 1)
			return;
		else {
			r = nx;
			c = ny;
			clean(0);
		}
	}
	else {
		nx = r + dx[d];
		ny = c + dy[d];
	}
	if (room[nx][ny] == 0) {
		r = nx;
		c = ny;
		d = (d + 3) % 4;
		dir = d;
		clean(0);
	}
	else {
		d = (d + 3) % 4;
		clean(turn + 1);
	}

}
int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &room[i][j]);
		}
	}
	dir = d;
	clean(0);
	printf("%d\n", ans);
}
