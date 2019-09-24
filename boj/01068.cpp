#include <iostream>
using namespace std;

int n;
int root;
int dlt;
int ans;
int parent[50][50];

void initParent() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			parent[i][j] = -1;
		}
	}
}

void travel(int root) {
	bool flag = false;
	for (int i = 0; i < 50; i++) {
		if (parent[root][i] != -1 && parent[root][i] != dlt) {
			travel(parent[root][i]);
			flag = true;
		}
	}
	if (!flag)
		ans++;
}

int main() {
	initParent();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int prt;
		cin >> prt;
		if (prt == -1) {
			root = i;
			continue;
		}
		int j = 0;
		while (parent[prt][j] != -1)
			j++;
		parent[prt][j] = i;
	}
	cin >> dlt;
	if(dlt != root)
		travel(root);

	cout << ans << '\n';


}
