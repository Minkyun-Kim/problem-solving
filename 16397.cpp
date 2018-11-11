#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[100000];
bool check[100000];

int pushA(int x) {
	int i = 1;
	for (; x - i >= 0; i *= 10);
	i /= 10;
	return x - i;
}

int main() {
	int n, t, g;
	cin >> n >> t >> g;
	if (n > g)
		cout << "ANG" << '\n';
	arr[n] = 0;
	queue<int> q;
	q.push(n);
	check[n] = true;
	while (!q.empty()) {
		int pos = q.front();
		q.pop();
		if (pos == g) {
			if (arr[pos] <= t)
				cout << arr[pos] << '\n';
			else
				cout << "ANG" << '\n';
			break;
		}
		if (pos + 1 <= 99999 && !check[pos+1]) {
			check[pos + 1] = true;
			arr[pos + 1] = arr[pos] + 1;
			q.push(pos + 1);
		}
		if (pos * 2 <= 99999 && !check[pushA(pos*2)]) {
			check[pushA(pos * 2)] = true;
			arr[pushA(pos * 2)] = arr[pos] + 1;
			q.push(pushA(pos * 2));
		}
	}
	return 0;
}
