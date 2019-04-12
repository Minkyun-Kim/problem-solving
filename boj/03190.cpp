#include <iostream>
#include <queue>
using namespace std;

int n, k, L;
queue<pair<int, int> > snake;
int dir = 1;
int x, y;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int ans;
int Csize;
int time;
int getTime;
char c;
int apple[100][100];

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		apple[x-1][y-1] = 1;
	}
	snake.push(make_pair(0, 0));
	cin >> L;
	x = 0;
	y = 0;
	apple[x][y] = 2;
	for (int i = 0; i < 101; i++) {
		if(i < L)
			cin >> getTime >> c;
		while(1) {
			time++;
			x += dx[dir];
			y += dy[dir];
			if (x < 0 || x >= n || y < 0 || y >= n) {
				cout << time << '\n';
				return 0;
			}
			if (apple[x][y] == 1) {
				snake.push(make_pair(x, y));
				apple[x][y] = 2;
			}
			else if(apple[x][y] == 2){
				cout << time << '\n';
				return 0;
			}
			else {
				pair<int, int> pr = snake.front();
				snake.pop();
				apple[pr.first][pr.second] = 0;
				snake.push(make_pair(x, y));
				apple[x][y] = 2;
			}
			if (time == getTime) {
				if (c == 'D') 
					dir = (dir + 1) % 4;
				else 
					dir = (dir + 3) % 4;
				break;
			}
		}
	}
	cout << time << '\n';
	return 0;
}
