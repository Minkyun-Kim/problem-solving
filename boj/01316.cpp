#include <iostream>
using namespace std;

char s[101];
bool check[26];

void initCheck() {
	for (int i = 0; i < 26; i++) {
		check[i] = false;
	}
}

bool groupWord() {
	initCheck();

	int i = 0;
	while (s[i] != '\0') {
		if (check[s[i] - 'a'] && s[i-1] != s[i]) {
			return false;
		}
		else {
			check[s[i] - 'a'] = true;
		}
		i++;
	}
	return true;
}

int main() {
	int ans=0, n;
	cin >> n;
	while (n--) {
		cin >> s;
		if (groupWord()) {
			ans++;
		}
	}
	cout << ans << '\n';

}
