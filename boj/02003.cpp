#include <iostream>
using namespace std;

int arr[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	int sum = 0;
	int first = 0, last = 0;
	sum = arr[first];
	while (last < n) {
		if (sum == m) {
			ans++;
			sum -= arr[first++];
			if (++last >= n)
				break;
			sum += arr[last];
		}
		else if (sum > m) {
			sum -= arr[first++];
		}
		else if (sum < m) {
			if (++last >= n)
				break;
			sum += arr[last];
		}
	}

	cout << ans << '\n';
}
