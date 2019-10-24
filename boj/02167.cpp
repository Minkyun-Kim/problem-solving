#include <iostream>
using namespace std;

int n, m, k;
int _x1, locY1, locX2, locY2;
int arr[301][301];

int getArraySum() {
	int sum = arr[locX2][locY2];
	if (_x1 > 1) {
		sum -= arr[_x1 - 1][locY2];
	}
	if (locY1 > 1) {
		sum -= arr[locX2][locY1 - 1];
	}
	if (_x1 > 1 && locY1 > 1) {
		sum += arr[_x1 - 1][locY1 - 1];
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];

			if (i > 1) {
				arr[i][j] += arr[i - 1][j];
			}

			if (j > 1) {
				arr[i][j] += arr[i][j - 1];
			}

			if (i > 1 && j > 1) {
				arr[i][j] -= arr[i - 1][j - 1];
			}
		}
	}
	cin >> k;
	while (k--) {
		cin >> _x1 >> locY1 >> locX2 >> locY2;
		cout << getArraySum() << '\n';
	}

}
