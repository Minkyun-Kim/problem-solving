#include <iostream>
using namespace std;

int n, m, k;
int arr[20][20];
int x, y, r, c;
int dice[6];
int tDice[6];
int dx[] = {0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
		
	for (int i = 0; i < k; i++) {
		int d;
		cin >> d;
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue;
		}
		if (d == 1) {
			dice[0] = tDice[4];
			dice[2] = tDice[5];
			dice[4] = tDice[2];
			dice[5] = tDice[0];
		}
		else if (d == 2) {
			dice[0] = tDice[5];
			dice[2] = tDice[4];
			dice[4] = tDice[0];
			dice[5] = tDice[2];

		}
		else if (d == 3) {
			dice[2] = tDice[3];
			dice[1] = tDice[2];
			dice[0] = tDice[1];
			dice[3] = tDice[0];
			
		}
		else {
			dice[0] = tDice[3];
			dice[3] = tDice[2];
			dice[2] = tDice[1];
			dice[1] = tDice[0];

		}
		cout << dice[0] << '\n';
		if (arr[nx][ny] != 0) {
			dice[2] = arr[nx][ny];
			arr[nx][ny] = 0;
		}
		else {
			arr[nx][ny] = dice[2];
		}
		for (int j = 0; j < 6; j++) {
			tDice[j] = dice[j];
		}
		x = nx;
		y = ny;

	}
	return 0;
}
