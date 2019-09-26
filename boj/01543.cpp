#include <iostream>
#include <string>
using namespace std;

string s;
string sub;
int ans = 0;

bool isSubStr(int _start) {
	int subSize = sub.size();
	for (int i = 0; i < subSize; i++) {
		if (sub[i] != s[_start]) {
			return false;
		}
		_start++;
	}
	return true;
}

int main() {
	getline(cin, s);
	cin >> sub;
	int sSize = s.size();
	int subSize = sub.size();
	int i = 0;
	while (i + subSize <= sSize) {
		if (isSubStr(i)) {
			i += subSize;
			ans++;
		}
		else {
			i++;
		}
	}

	cout << ans << '\n';

}
