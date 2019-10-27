#include <iostream>
using namespace std;

int t, k;
int gaus[50];

int dfs(int num) {
	for (int i = 0; i < 48; i++) {
		if (gaus[i] > num)
			break;
		for (int j = i; j < 49; j++) {
			if (gaus[i] + gaus[j] > num)
				break;
			for (int k = j; k < 50; k++) {
				if (gaus[i] + gaus[j] + gaus[k] == num)
					return 1;
				if (gaus[i] + gaus[j] + gaus[k] > num)
					break;
			}
		}
	}
	return 0;
}

void initGaus() {
	for (int i = 1; i <= 50; i++) {
		gaus[i-1] = i * (i + 1) / 2;
	}
}

int main() {
	initGaus();
	cin >> t;
	while (t--) {
		cin >> k;
		cout << dfs(k) << '\n';
	}


}
