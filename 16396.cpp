#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, a, b;
	cin >> n;
	vector<int> v(10001);
	while (n--) {
		cin >> a >> b;
		for (int i = a; i < b; i++) {
			v[i] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= 10000; i++) {
		if (v[i] == 1)
			ans++;
	}
	cout << ans << '\n';
	return 0;
}
