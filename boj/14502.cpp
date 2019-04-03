#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int lab[8][8];
int temp[8][8];
int maxi = 0;
int a, b;
int nx[4] = { -1, 0, 1, 0 };
int ny[4] = { 0, 1, 0, -1 };

void reset(int to[8][8], int from[8][8]) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			to[i][j] = from[i][j];
		}
	}
	return;
}
void spread() {
	queue<pair<int, int> > q;
	int spreadLab[8][8];
	reset(spreadLab, temp);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (spreadLab[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> pr = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = pr.first + nx[i];
			int n_y = pr.second + ny[i];
			//if (n_x == -1 || n_x == a || n_y == -1 || n_y == b)
				//continue;
			if (0 <= n_x && n_x < a && 0 <= n_y && n_y < b) {
				if (spreadLab[n_x][n_y] == 0) {
					spreadLab[n_x][n_y] = 2;
					q.push(make_pair(n_x, n_y));
				}
			}
		}

	}
	int cnt = 0;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (spreadLab[i][j] == 0)
				cnt++;
		}
	}
	maxi = cnt > maxi? cnt : maxi;
	return;
}

void wall(int cnt) {

	if (cnt == 3) {
		spread();
		return;
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (temp[i][j] == 0) {
				temp[i][j] = 1;
				wall(cnt+1);
				temp[i][j] = 0;
			}
		}
	}
	return;
}

int main() {
	scanf("%d %d", &a, &b);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf("%d", &lab[i][j]);
		}
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (lab[i][j] == 0) {
				reset(temp, lab);
				temp[i][j] = 1;
				wall(1);
				temp[i][j] = 0;
			}
		}
	}
	printf("%d\n", maxi);
	return 0;
}
