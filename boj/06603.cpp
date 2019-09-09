#include <iostream>
#include <vector>
using namespace std;

int arr[49];
int k;

void lotto(vector<int> &v, int idx) {
	if (v.size() == 6) {
		for (int num : v) {
			cout << num << ' ';
		}
		cout << '\n';
	}
	for (int i = idx; i < k; i++) {
		v.push_back(arr[i]);
		lotto(v, i + 1);
		v.pop_back();
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (1) {
		cin >> k;
		if (k == 0)
			break;
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		vector<int> v;
		lotto(v,0);
		cout << '\n';

	}
}
