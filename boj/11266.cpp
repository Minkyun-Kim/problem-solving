#include <iostream>
#include <vector>
using namespace std;

vector<int> v[10001];
int isCut[10001];
int order[10001];
int curOrder;

int _min(int& a, int& b) {
	return a < b ? a : b;
}

int dfs(int here, bool isRoot) {
	order[here] = ++curOrder;
	int miniOrder = order[here];

	int child = 0;//for root

	for (int i = 0; i < v[here].size(); i++) {
		int next = v[here][i];
		if (order[next]) {
			miniOrder = _min(miniOrder, order[next]);
			continue;
		}
		child++;
		int prev = dfs(next, false);
		if (!isRoot && prev >= order[here])
			isCut[here] = true;
		miniOrder = _min(miniOrder, prev);
	}
	if (isRoot)
		isCut[here] = (child >= 2);
	return miniOrder;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	for (int i = 1; i <= n; i++) {
		if (!order[i])
			dfs(i, true);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (isCut[i])
			ans++;
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		if (isCut[i])
			cout << i << ' ';
	}
}
