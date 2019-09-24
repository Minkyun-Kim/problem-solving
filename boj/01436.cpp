#include <iostream>
using namespace std;

bool isEnd(int num) {
	int mod;
	int cnt = 0;
	while (num) {
		mod = num % 10;
		if (mod != 6) {
			cnt = 0;
		}
		else {
			cnt++;
			if (cnt == 3) {
				return true;
			}
		}
		num /= 10;
	}
	return false;

}

int main() { 
	int n;
	cin >> n;
	int i = 0;
	int cnt = 0;
	while (1) {
		if (isEnd(i)) {
			cnt++;
		}
		if (cnt == n) {
			cout << i << '\n';
			break;
		}
		i++;
	}
}
