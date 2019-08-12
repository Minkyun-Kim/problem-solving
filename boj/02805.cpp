#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, min = 0, max = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	int ans = 0;
	min = 0;
	while (min <= max) {
		int mid = min + (max - min) / 2;
		long long sum = 0; //높이 20억이 100만개 있을 수 있으므로 범위를 초과할 수 있음에 유의하자
		for (int i = 0; i < n; i++) {
			if (arr[i] > mid)
				sum += arr[i] - mid;
		}
		if (sum >= m) {
			if (mid > ans)
				ans = mid;
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}
	cout << ans << '\n';

}
