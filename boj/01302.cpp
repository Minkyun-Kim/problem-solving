#include <iostream>
#include <map>
#include <string>
using namespace std;

int n;
string s;
map<string, int> mp;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int cnt = mp[s];
		mp[s] = cnt + 1;
	}
	int maxi = 0;
	for (auto m : mp) {
		if (maxi < m.second) {
			s = m.first;
			maxi = m.second;
		}
		else if (maxi == m.second) {
			if (s> m.first) {
				s = m.first;
				maxi = m.second;
			}
		}
	}
	cout << s << '\n';
}
