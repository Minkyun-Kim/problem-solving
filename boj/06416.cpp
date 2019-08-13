#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	vector<pair<int, int> > edge;
	vector<pair<int, int> > indegree;
	set<int> s;
	int k = 1;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1)return 0;
		else if (a == 0 && b == 0) {
			int ans = 1;
			for (int i = 0; i < indegree.size(); i++) {
				if (indegree[i].second > 1) {
					ans = 0;
					break;
				}
			}
			if (edge.size() != s.size() - 1)
				ans = 0;
			if (s.size() == 0) ans = 1;
			if (ans) {
				cout << "Case " << k << " is a tree." << '\n';
			}
			else {
				cout << "Case " << k << " is not a tree." << '\n';
			}
			k++;
			s.clear();
			edge.clear();
			indegree.clear();
		}
		else {
			edge.push_back({ a, b });
			s.insert(a);
			s.insert(b);
			int flag = 1;
			int vSize = indegree.size();
			for (int i = 0; i < vSize; i++) {
				if(indegree[i].first == b){
					flag = 0;
					indegree[i].second++;
					break;
				}
			}
			if (flag) {
				indegree.push_back({ b, 1 });
			}
		}

	}

}
