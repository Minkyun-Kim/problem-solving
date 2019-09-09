#include <iostream>
using namespace std;

int t, n, m, idx;
int arr[100];
int imp[10];

void reset() {
	for (int i = 0; i < 10; i++) {
		imp[i] = 0;
	}
	idx = 0;
}

bool hasHigh(int importance) {
	for (int i = importance+1; i < 10; i++) {
		if (imp[i])
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		reset();
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			imp[arr[i]]++;
		}
		int answer = 1;
		while (1) {
			if (arr[idx] == 0) {
				idx++;
				idx %= n;
				continue;
			}
			if (!hasHigh(arr[idx])) {
				//출력
				if (idx == m)
					break;
				imp[arr[idx]]--;
				arr[idx] = 0;
				answer++;
			}
			idx++;
			idx %= n;
		}
		cout << answer << '\n';
	}

}
