#include <iostream>
using namespace std;

long long cache[100][100];
int map[100][100];
int n;

long long jump(int x, int y) {
	if (x >= n ||  y >= n)
		return 0;
	if (x == n - 1 && y == n - 1)
		return 1;
	if (map[x][y] == 0)
		return 0;
	long long& ret = cache[x][y];
	if (ret != -1)
		return ret;

	int jumpSize = map[x][y];
	return ret = jump(x + jumpSize, y) + jump(x, y + jumpSize);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			cache[i][j] = -1;
		}
	}

	cout << jump(0, 0) << '\n';


}
