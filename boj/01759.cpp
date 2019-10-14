#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int L, C;
char arr[26];
vector<char> v;

bool condition() {
	int cntMo = 0;
	int cntJa = 0;
	for (char c : v) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			cntMo++;
		else
			cntJa++;
	}
	if (cntMo < 1 || cntJa < 2)
		return false;
	return true;
}

void dfs(int pos, int cnt) {
	if (cnt == L) {
		if (!condition()) {
			return;
		}
		else {
			for (char c : v) {
				cout << c;
			}
			cout << '\n';
			return;
		}
	}
	for (int i = pos + 1; i < C; i++) {
	v.push_back(arr[i]);
		dfs(i, cnt + 1);
	v.pop_back();
	}
}

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + C);

	dfs(-1, 0);


}
