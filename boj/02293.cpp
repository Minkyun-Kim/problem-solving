#include <iostream>
using namespace std;

int n, k;
int coin[101];
int arr[2][10001];
int ans;

void cp() {
	for (int i = 0; i < 10001; i++) {
		arr[0][i] = arr[1][i];
	}
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}
	arr[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j - coin[i] >= 0) {
				arr[1][j] = arr[1][j - coin[i]] + arr[0][j];
			}
			else {
				arr[1][j] = arr[0][j];
			}
		}
		cp();
	}


	cout << arr[1][k] << '\n';
}
