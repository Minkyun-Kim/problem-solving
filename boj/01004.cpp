#include <iostream>
using namespace std;

int startX, startY, endX, endY;
int cX, cY, r;
int t, n;

int _abs(int a) {
	if (a < 0) {
		return -1 * a;
	}
	else
		return a;
}

int isInside(int posX, int posY) {
	int xlen = _abs(posX - cX);
	int ylen = _abs(posY - cY);
	if (xlen * xlen + ylen * ylen > r* r) {
		return 1;
	}
	return -1;
}

bool isBoundary() {
	if (isInside(startX, startY) * isInside(endX, endY) == -1) {
		return true;
	}
	return false;
}

int main() {
	cin >> t;
	while (t--) {
		int ans = 0;
		cin >> startX >> startY >> endX >> endY;

		cin >> n;
		while (n--) {
			cin >> cX >> cY >> r;
			if (isBoundary())
				ans++;
		}
		cout << ans << '\n';
	}

}
