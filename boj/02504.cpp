#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<int> st;
	string s;
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (st.empty() || s[i] == '('  || s[i] == '[') {
			st.push(s[i]);
			continue;
		}
		if (st.empty() && (s[i] == ')' || s[i] == ']')) {
			cout << 0 << '\n';
			return 0;
		}

		if (s[i] == ')') {
			int sum = 0;
			while (1) {
				if (st.top() == '[') {
					cout << 0 << '\n';
					return 0;
				}
				else if (st.top() == '(') {
					if (sum == 0)
						sum = 1;
					sum *= 2;
					st.pop();
					st.push(sum);
					break;
				}
				else {
					sum += st.top();
					st.pop();
				}
				if (st.empty())
					break;
			}


		}
		if (s[i] == ']') {
			int sum = 0;
			while (1) {
				if (st.top() == '(') {
					cout << 0 << '\n';
					return 0;
				}
				else if (st.top() == '[') {
					if (sum == 0)
						sum = 1;
					sum *= 3;
					st.pop();
					st.push(sum);
					break;
				}
				else {
					sum += st.top();
					st.pop();
				}
				if (st.empty())
					break;
			}
		}

	}
	int sum = 0;
	while (!st.empty()) {
		int top = (int)st.top();
		if (top =='(' || top == ')' || top == '[' || top == ']') {
			cout << 0 << '\n';
			return 0;
		}
		sum += top;
		st.pop();
	}
	cout << sum << '\n';
}
