#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct{
	int weight;
	int from;
	int to;
}tPair;
typedef struct{
	int first;
	int second;
}_pair;

int _distance[200001];
bool check[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, e;
	cin >> n >> e;
	int k;
	cin >> k;

	for (int i = 1; i <= n; i++) {
		_distance[i] = 2100000000;
	}
	_distance[k] = 0;
	priority_queue<pair<int, int> > pq;
	vector<vector<pair<int, int> > > v(n + 1);
	for (int i = 0; i < e; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		v[from].push_back({ weight, to });
	}
	pq.push({ 0, k });

	while (!pq.empty()) {
		pair<int, int> pr = pq.top();
		pq.pop(); 
		check[pr.second] = true;
		pr.first *= -1;
		int from = pr.second;
		int vSize = v[from].size();
		for (int i = 0; i < vSize; i++) {
			int to = v[from][i].second;
			if (!check[to] && _distance[to] > _distance[from] + v[from][i].first) {
				_distance[to] = _distance[from] + v[from][i].first;
				pq.push({ -1 * _distance[to], to });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (_distance[i] == 2100000000)
			cout << "INF" << '\n';
		else {
			cout << _distance[i] << '\n';
		}
	}
}
