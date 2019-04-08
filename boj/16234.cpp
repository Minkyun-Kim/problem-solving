#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;


int n, L, R;
int arr[50][50];
bool check[50][50];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool out = true;
int ans;

int main() {
	scanf("%d %d %d", &n, &L, &R);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	queue<pair<int, int> > q;
	vector<pair<int, int> > v;
	while (out) {
		out = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j]) {
					q.push(make_pair(i, j));
					check[i][j] = true;
					v.push_back(make_pair(i, j));
				}
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < n
							&& abs(arr[nx][ny] - arr[x][y]) >= L
							&& abs(arr[nx][ny] - arr[x][y]) <= R
							&& !check[nx][ny]) {
							q.push(make_pair(nx, ny));
							check[nx][ny] = true;
							v.push_back(make_pair(nx, ny));
						}
					}

				}
				int size = v.size();
				if (size < 2) {
					v.clear();
					continue;
				}
				int sum = 0;
				for (int k = 0; k < size; k++) {
					int x = v[k].first;
					int y = v[k].second;
					sum += arr[x][y];
					out = true;
				}
				int avg = sum / size;
				for (int k = 0; k < size; k++) {
					int x = v[k].first;
					int y = v[k].second;
					arr[x][y] = avg;
				}
				v.clear();
			}
		}
		if (out == true)
			ans++;
		else
			break;
		
		memset(check, 0, sizeof(check));
	}
	printf("%d\n", ans);
}
