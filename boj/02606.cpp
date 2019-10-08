#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool arr[101];
int ans;

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int> > v(n+1);
	while (k--) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	queue<int> q;

	q.push(1);
	arr[1] = true;

	while (!q.empty()) {
		int virus = q.front();
		q.pop();
		for (int i = 0; i < v[virus].size(); i++) {
			int next = v[virus][i];
			if (!arr[next]) {
				q.push(next);
				arr[next] = true;
				ans++;
			}
		}
	}

	cout << ans << '\n';

}
