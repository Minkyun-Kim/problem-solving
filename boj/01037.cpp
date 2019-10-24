#include <iostream>
using namespace std;

int n, _min = 1000001, _max = 0;

int getMinBetween(int a, int b) {
	return a > b ? b : a;
}
int getMaxBetween(int a, int b) {
	return a > b ? a : b;
}

int main() {

	cin >> n;
	while (n--) {
		int measure;
		cin >> measure;
		_min = getMinBetween(_min, measure);
		_max = getMaxBetween(_max, measure);
	}
	cout << _min * _max << '\n';
}
