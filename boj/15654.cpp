#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
int arr[9];
bool check[9];

void dfs(int pivot, int cnt) {
	if (cnt == 0) {
		for (int num : v) {
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i])
			continue;
		check[i]= true;
		v.push_back(arr[i]);
		dfs(i, cnt - 1);
		v.pop_back();
		check[i]= false;

	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n+1);
	dfs(1, m);
}
