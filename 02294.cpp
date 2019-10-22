#include <iostream>
using namespace std;

int n, k;
int coin[101];
int arr[10001];

int _min(int a, int b) {
	if (a == 0) {
		return b;
	}
	return a > b ? b : a;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}
	for (int i = 1; i <= k; i++) {
		arr[i] = 10001;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
				arr[j] = _min(arr[j], arr[j - coin[i]]+1) ;
		}
	}
	if (arr[k] == 10001)
		cout << -1 << '\n';
	else
		cout << arr[k] << '\n';
}
