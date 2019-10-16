#include <iostream>
using namespace std;

int t, h, w, n;

int main() {
	cin >> t;
	while (t--) {
		cin >> h >> w >> n;
		n--;
		int floor = n % h;
		int room = n / h + 1;
		cout << floor+1;
		if (room < 10)
			cout << 0 << room << '\n';
		else
			cout << room << '\n';
	}

}
