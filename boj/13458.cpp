#include <iostream>
#include <vector>
using namespace std;

int n, b, c;
long long ans;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> b >> c;
	for (int i = 0; i < n; i++) {
		if (v[i] <= b) {
			ans++;
			continue;
		}
		ans++;
		v[i] -= b;
		ans += v[i] / c;
		if (v[i] % c != 0)
			ans++;
	}
	cout << ans << '\n';
}
