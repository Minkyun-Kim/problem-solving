#include <iostream>
using namespace std;

int _left = 1, _right;
long long _pow = 1;
long long number[10];

void _count(int num) {
	while (num) {
		number[num % 10]+=_pow;
		num /= 10;
	}
}

int main() {
	cin >> _right;
	while (_left <= _right) {
		while (_left % 10 != 0 && _left <= _right) {
			_count(_left);
			_left++;
		}
		if (_left > _right)
			break;
		while (_right % 10 != 9 && _left <= _right) {
			_count(_right);
			_right--;
		}
		long long cnt = (_right / 10 - _left / 10 + 1) * _pow;
		for (int i = 0; i < 10; i++) {
			number[i] += cnt;
		}
		_pow *= 10;
		_left /= 10;
		_right /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << number[i] << ' ';
	}
	cout << '\n';

}
