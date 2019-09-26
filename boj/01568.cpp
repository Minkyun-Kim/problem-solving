#include <iostream>
using namespace std;

int n;

int main() {
	int k=1;
	int time = 0;
	cin >> n;
	while (n) {
		if (n - k < 0) {
			k = 1;
		}
		else {
			n -= k;
			k++;
			time++;
		}
	}
	cout << time << '\n';

}
