#include <iostream>
using namespace std;

int n;
int ans=1;

int main() {
	cin >> n;
	int dis = 1;
	int acc = 1;
	while (n > acc) {
		acc += 6 * dis;
		dis++;
		ans++;
	}
	cout << ans << '\n';

	

}
