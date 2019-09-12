#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int n, w;

bool comp(int a, int b) {
	return a > b;
}

int _max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, comp);

	w = arr[0];
	for (int i = 1; i < n; i++) {
		w = _max(w, (i + 1) * arr[i]);
	}
	cout << w << '\n';

}
