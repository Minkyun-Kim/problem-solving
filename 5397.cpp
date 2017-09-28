#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n;
	stack<char> st;
	stack<char> temp;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '<') {
				if (!st.empty()) {
					temp.push(st.top());
					st.pop();
				}
			}
			else if (s[i] == '>') {
				if (!temp.empty()) {
					st.push(temp.top());
					temp.pop();
				}
			}
			else if (s[i] == '-') {
				if (!st.empty())
				st.pop();
			}
			else {
				st.push(s[i]);
			}
		}

		while (!st.empty()) {
			temp.push(st.top());
			st.pop();
		}
		while (!temp.empty()) {
			cout << temp.top();
			temp.pop();
		}
		cout << endl;
	}
}