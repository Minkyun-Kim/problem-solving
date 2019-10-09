#include <iostream>
using namespace std;

int n;
int arr[15];
int ans;

int _abs(int num) {
	return num >= 0 ? num : num * -1;
}

bool promising(int row) {
	for (int col = 0; col < row; col++) {
		if (arr[row] == arr[col] || _abs(arr[row] - arr[col]) == _abs(row - col)) {
			return false;
		}
	}
	return true;
}

void dfs(int pos) {
	if (pos == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		arr[pos] = i;
		if (promising(pos)) {
			dfs(pos + 1);
		}
	}

}

int main() {
	cin >> n;
	dfs(0);
	cout << ans << '\n';
}
