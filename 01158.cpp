#include <iostream>
#include <list>
#include <queue>
using namespace std;
int main() {
	int n, m, a = 0, cnt = 0;
	cin >> n >> m;
	queue<int> q;
	list<int> lst;
	for (int i = 1; i < n+1; i++)
		lst.push_back(i);
	list<int>::iterator it = lst.begin();
	list<int>::iterator pit;
	while (n--) {
		for (int i = 0; i < m-1; i++) {
			if (it == lst.end())
				it = lst.begin();
			if (++it == lst.end())
				it = lst.begin();
			else {}
		}
		q.push(*it);
		pit = ++it;
		lst.erase(--it);
		it = pit;
	}
	cout << "<";
	while (!q.empty()) {
		int ele = q.front();
		q.pop();
		if (!q.empty()) {
			cout << ele << ", ";
		}
		else {
			cout << ele<<">";
		}
	}
}
