#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int _gcd(int a, int b) {
	if (b == 0)
		return a;
	return _gcd(b, a%b);

}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int son = a*d + b*c;
	int mom = b*d;
	int gcd = _gcd(son, mom);
	cout << son / gcd << ' ' << mom / gcd << '\n';
}
