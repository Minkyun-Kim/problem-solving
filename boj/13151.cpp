#include <iostream>
#include <cstdio>
using namespace std;

int arr[51];

double prob(int n, int k, int i) {
	if (k == 0) 
		return 1.0;
	int cur = arr[i];
	arr[i]--;
	return (cur / (double)n) * prob(n - 1, k - 1, i);
}

int main() {
	int m, n = 0;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> arr[i];
		n += arr[i];
	}
	int k;
	cin >> k;
	double ans = 0.0;
	for (int i = 1; i <= m; i++) {
		ans += prob(n, k, i);
	}
	printf("%.9f", ans);
}
