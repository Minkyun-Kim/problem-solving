#include <iostream>
using namespace std;

int dist[101][101];

int min(int a, int b) {
	return a < b ? a : b;
}
int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			else
				dist[i][j] = 100000000;
		}
	}
	for (int i = 0; i < m; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		if(dist[from][to] > weight)
			dist[from][to] = weight;
	}
	for (int k = 1; k <= n; k++) {
		for (int from = 1; from <= n; from++) {
			for (int to = 1; to <= n; to++) {
				dist[from][to] = min(dist[from][to], dist[from][k] + dist[k][to]);
			}
		}

	}
	for (int from = 1; from <= n; from++) {
		for (int to = 1; to <= n; to++) {
			if (dist[from][to] == 100000000)
				cout << 0 << ' ';
			else
				cout << dist[from][to] << ' ';
		}
		cout << '\n';
	}
}
