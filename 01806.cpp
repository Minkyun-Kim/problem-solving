#include <iostream>
using namespace std;

int arr[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int start = 0, end = 0;
	int ans = 2100000000;
	int sum = 0;
	sum = arr[0];
	while (end < n) {
		if (sum >= s) {
			if (sum >= s && end - start + 1 < ans)
				ans = end - start + 1;
			sum -= arr[start];
			start++;
		}
		else {
			if (++end == n)
				break;
			sum += arr[end];
		}
	}
	if (ans == 2100000000)
		ans = 0;
	cout << ans << '\n';
}
