#include <iostream>
using namespace std;

int x, y, w, h;
int _min(int a, int b, int c, int d) {
	a = a < b ? a : b;
	c = c < d ? c : d;
	return a < c ? a : c;
}


int main() {
	cin >> x >> y >> w >> h;
	
	cout << _min(x, y, w - x, h - y) << '\n';
	
}
