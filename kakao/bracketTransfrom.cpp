#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isCorrect(string s) {
	stack<char> st;
	for (char ch : s) {
		if (ch == '(') {
			st.push('(');
		}
		else {
			if (st.empty()) {
				return false;
			}
		}
	}
	return true;

}

string solution(string p) {
	if (p.empty())
		return "";
	string answer = "";
	string u, v;
	int open = 0, close = 0;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') {
			open++;
		}
		else if (p[i] == ')') {
			close++;
		}
		u.push_back(p[i]);
		if (open == close) {
			for (int j = i+1; j < p.size(); j++) {
				v.push_back(p[j]);
			}
			break;
		}
	}
	if (isCorrect(u)) {
		return u + solution(v);
	}
	else {
		string temp;
		for (int i = 1; i < u.size() - 1; i++) {
			if (p[i] == '(')
				temp.push_back(')');
			else
				temp.push_back('(');
		}
		return "(" + solution(v) + ")" + temp;
	}
}
