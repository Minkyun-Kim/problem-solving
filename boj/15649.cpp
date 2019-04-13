#include <iostream>
#include <stack>
using namespace std;

int n, m;
int arr[8];
int check[8];
int temp[8];
stack<int> s;

void dfs(int cnt) {
	if (cnt == m) {
		int size = s.size();
		for (int i = 0; i < size; i++) {
			temp[i] = s.top();
			s.pop();
		}
		for (int i = size - 1; i >= 0; i--) {
			cout << temp[i] << ' ';
			s.push(temp[i]);
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check[i] == 1)
			continue;
		check[i] = 1;
		s.push(arr[i]);
		dfs(cnt + 1);
		s.pop();
		check[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	dfs(0);
}
