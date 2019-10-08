#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int parent[1000001];
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int _find(int a) {
	if (parent[a] == a)
		return a;
	else
		return parent[a] = _find(parent[a]);
}

void _union(int a, int b) {
	parent[_find(b)] = _find(a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			_union(b, c);

		}
		else {
			if (_find(b) == _find(c))
				cout << "yes" << '\n';
			else
				cout << "no" << '\n';

		}

	}

}
