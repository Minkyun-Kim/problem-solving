#include <iostream>
using namespace std;
int main() {
	int n, k=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		k += i;
	}
	cout << k << endl;
}