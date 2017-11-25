#include <iostream>
using namespace std;
int main() {
	int x, y, day=0;
	cin >> x >> y;
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 1; i <x; i++) {
		day += mon[i-1];
	}
	day += y;
	switch (day % 7) {
	case 0:
		cout << "SUN" << endl;
		break;
	case 1:
		cout << "MON" << endl;
		break;
	case 2:
		cout << "TUE" << endl;
		break;
	case 3:
		cout << "WED" << endl;
		break;
	case 4:
		cout << "THU" << endl;
		break;
	case 5:
		cout << "FRI" << endl;
		break;
	case 6:
		cout << "SAT" << endl;
		break;

	}
}