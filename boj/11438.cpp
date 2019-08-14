#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
	int first;
	int second;
}_pair;

int depth[100001];
int parent[18][100001];
bool check[100001];

void _swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int getParent(int pow, int node) {
	if (pow == 0)
		return parent[pow][node];
	if (parent[pow][node] == 0)
		return getParent(pow-1, parent[pow-1][node]);
	else {
		return parent[pow - 1][parent[pow-1][node]];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a, b;
	cin >> n;
	vector<vector<int> > v(100001);
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	int max_depth = 0;
	check[1] = true;
	//dfs 로 depth 구하기 + parent[0] 채우기
	while(!q.empty()){
		int node = q.front();
		q.pop();
		int vSize = v[node].size();
		for (int i = 0; i < vSize; i++) {
			int nextNode = v[node][i];
			if (!check[nextNode]) {
				check[nextNode] = true;
				depth[nextNode] = depth[node] + 1;
				parent[0][nextNode] = node;
				q.push(nextNode);
				if (max_depth < depth[nextNode])
					max_depth = depth[nextNode];
			}
		}

	}
	//DP이용 parent[k][v] 채우기
 	for (int k = 1; k <= 17; k++) {
		for (int v = 1; v <= n; v++) {
			parent[k][v] = parent[k - 1][parent[k - 1][v]];
		}
	}
	//공통조상찾기
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (depth[a] > depth[b])
			swap(a, b);
		//depth 맞추기
		int diff = depth[b] - depth[a];
		for (int j = 17; j >= 0; j--) {
			if (diff & (1 << j)) {
				b = parent[j][b];
			}
		}
		//공통조상 올라가기
		while (a != b) {
			int pow = 0;
			while (parent[pow][a] != parent[pow][b]) {
				pow++;
			}
			if (parent[0][a] == parent[0][b]) {
				a = parent[0][a];
				b = parent[0][b];
				break;
			}
			else {
				a = parent[pow - 1][a];
				b = parent[pow - 1][b];
			}
		}
		cout << a << '\n';
	}
}
