#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
vector<int> idx;

void dfs(int index, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << v[idx[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = index; i < v.size(); i++) {
			idx[cnt] = i;
			dfs(i, cnt + 1);
	}
}

int main() {
	cin >> n >> m;
	v.resize(n);
	idx.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
		
	sort(v.begin(), v.end());
	dfs(0, 0);

}
