#include <iostream>
using namespace std;

int arr[100000];
int n, m;
int _left = 1, _right = 1000000000;

int canSpend(int k) {
	int times = 0;
	int budget = 0;
	for (int i = 0; i < n; i++) {
		if (budget < arr[i]) {
			times++;
			budget = k;
		}
		budget -= arr[i];

	}
	return times;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		_left = _left > arr[i] ? _left : arr[i];
	}

	while (_left < _right) {
		int mid = (_right - _left) / 2 + _left;
		if (canSpend(mid) > m) {
			_left = mid+1;
		}
		else {
 			_right = mid;
		}
	}
	cout << _left << '\n';
	
}
