#include <iostream>
using namespace std;

int _ceil(double a) {
	if (a - (int)a)
		return (int)a + 1;
	else
		return (int)a;
}

int main() {
	int a, b, v;
	cin >> a >> b >> v;
	cout << 1 + _ceil((double)(v - a) / (a - b)) << '\n';
}
