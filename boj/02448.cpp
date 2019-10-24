#include <iostream>
using namespace std;

int n;
char arr[3072][6144];

void star(int n, int x, int y) {
	if (n == 3) {
		arr[x][y] = '*';
		arr[x+1][y-1] = '*';
		arr[x+1][y+1] = '*';
		arr[x+2][y-2] = '*';
		arr[x+2][y-1] = '*';
		arr[x+2][y] = '*';
		arr[x+2][y+1] = '*';
		arr[x+2][y+2] = '*';
		return;
	}
	star(n / 2, x, y);
	star(n / 2, x + n / 2, y - n / 2);
	star(n / 2, x + n / 2, y + n / 2);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	//배열 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			if (j == 2 * n - 1)
				arr[i][j] = '\0';
			else
				arr[i][j] = ' ';
		}
	}
	star(n, 0, n - 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2*n-1; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}

}
