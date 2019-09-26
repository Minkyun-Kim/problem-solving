#include <iostream>
using namespace std;

int arr[5];

int main() {
	int ans = 1;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	while (1) {
		int cnt = 0;
		for (int i = 0; i < 5; i++) {
			if (ans % arr[i] == 0) {
				cnt++;
			}
		}
		if (cnt >= 3) {
			break;
		}
		ans++;
	}
	cout << ans << '\n';
}
