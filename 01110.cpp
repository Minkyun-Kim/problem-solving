#include <iostream>
using namespace std;
int main() {
	int n, save;
	cin >> n;
	save = n;
	int a, b, c, cnt=0;
	while (true) {
		if (n < 10)a = 0;
		else a = (n - (n % 10)) / 10;
		b = n % 10;
		c = (a + b)%10;
		n = b * 10 + c;
		cnt++;
		if (save == n) break;
	}
	cout << cnt << endl;
}