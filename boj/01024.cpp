#include <iostream>
using namespace std;

void showseq(int len, int x) {
	for (int i = 0; i < len; i++) {
		cout << x+i << ' ';
	}
	cout << '\n';
}
int main() {

	int n, L;
	cin >> n >> L;

	for (int i = L; i <= 100; i++) {
		int t = n - i * (i - 1) / 2;
		if (t % i == 0 && t >= 0) {
			showseq(i, t / i);
			return 0;
		}
	}
	cout << -1 << '\n';

}
