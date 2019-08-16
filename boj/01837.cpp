#include <iostream>
#include <string>
using namespace std;

int check[1000001];
string p;

bool isDivided(int r) {
	int mod = 0;
	if (r == 999961) {
		mod = 0;
	}
	for (int i = 0; i < p.size(); i++) {
		mod *= 10;
		mod+=p[i] - '0';
		mod %= r;
	}
	return mod == 0;
}

int main() {

	int k;
	cin >> p >> k;
	for (int i = 2; i < k; i++) {
		if (check[i])
			continue;

		for (int j = i; j <= k; j+=i) {
			check[j] = 1;
		}
		if (isDivided(i)) {
			//p가 k로 나누어지면
			cout << "BAD " << i << '\n';
			return 0;
		}

	}
	cout << "GOOD" << '\n';


}
