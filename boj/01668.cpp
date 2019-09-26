#include <iostream>
using namespace std;

int n;
int trophys[50];
int ans_left = 1, ans_right = 1;
int _max;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> trophys[i];
	}
	_max = trophys[0];
	for (int i = 1; i < n; i++) {
		if (_max < trophys[i]) {
			ans_left++;
			_max = trophys[i];
		}
	}
	_max = trophys[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (_max < trophys[i]) {
			ans_right++;
			_max = trophys[i];
		}
	}
	cout << ans_left << '\n' << ans_right << '\n';


}
