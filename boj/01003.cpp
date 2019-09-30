#include <iostream>
using namespace std;

int t;
int n;
int zero[41] = { 1, 0, 1, 1 };
int one[41] = { 0, 1, 1, 2 };

int fibo0(int f) {
	if (f < 4)
		return zero[f];
	else if(zero[f] > 0){
		return zero[f];
	}
	else {
		return zero[f] = fibo0(f - 1) + fibo0(f - 2);
	}
}
int fibo1(int f) {
	if (f < 4)
		return one[f];
	else if(one[f] > 0){
		return one[f];
	}
	else {
		return one[f] = fibo1(f - 1) + fibo1(f - 2);
	}
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 0) {
			cout << 1 << ' ' << 0 << '\n';
		}
		else if (n == 1) {
			cout << 0 << ' ' << 1 << '\n';
		}
		else {
			cout << fibo0(n) << ' ' << fibo1(n) << '\n';
		}
	}
}
