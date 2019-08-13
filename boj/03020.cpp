#include <iostream>
using namespace std;

int bottom[500001];
int up[500001];
int crash[500001];
int _count[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, h;
	cin >> n >> h;
	
	for (int i = 0; i < n/2; i++) {
		int b, u;
		cin >> b >> u;
		bottom[b]++;
		up[u]++;
	}
	for (int i = h - 1; i >= 1; i--) {
		bottom[i] += bottom[i + 1];
		up[i] += up[i + 1];
	}
	for (int i = 1; i <= h; i++) {
		crash[i] = bottom[i] + up[h - i + 1];
	}
	for (int i = 1; i <= h; i++) {
		_count[crash[i]]++;
	}
	for (int i = 0; i <= n; i++) {
		if (_count[i] != 0) {
			cout << i << ' ' << _count[i] << '\n';
			return 0;
		}
	}
}
