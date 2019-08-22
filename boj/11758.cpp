#include <iostream>
using namespace std;

int main() {
	int ax, ay, bx, by, cx, cy;
	cin >> ax >> ay;
	cin >> bx >> by;
	cin >> cx >> cy;
	int ccw = ax*by + bx*cy + cx*ay - bx*ay - cx*by - cy*ax;
	if (ccw > 0)
		cout << 1 << '\n';
	else if (ccw < 0)
		cout << -1 << '\n';
	else
		cout << 0 << '\n';
	return 0;
} 
