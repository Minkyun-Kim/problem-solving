#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
int arr[50][50];
int visited[13];
int ans = 2100000000;
int temp;
int h_size;
int c_size;
vector<pair<int, int> > home;
vector<pair<int, int> > chic;

int get_sum() {
	int sum = 0;
	for (int i = 0; i < h_size; i++) {
		int mini = 2100000000;
		for (int j = 0; j < c_size; j++) {
			if (!visited[j])
				continue;
			int len = abs(home[i].first - chic[j].first) + abs(home[i].second - chic[j].second);
			if (mini > len)
				mini = len;
		}
		sum += mini;
	}
	return sum;
}

void dfs(int i, int k) {
	if (i > c_size)
		return;
	if (k == m) {
		temp = get_sum();
		if (ans > temp)
			ans = temp;
		return;
	}
	visited[i] = 1;
	dfs(i + 1, k + 1);
	visited[i] = 0;
	dfs(i + 1, k);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				home.push_back(make_pair(i, j));
			}
			else if (arr[i][j] == 2) {
				chic.push_back(make_pair(i, j));
			}
		}
	}
	h_size = home.size();
	c_size = chic.size();
	dfs(0, 0);
	
	cout << ans << '\n';
}
