#include <iostream>
#include <stack>
using namespace std;

int n;
int cal_idx = 0;
char calculator[200000];
bool isSequence = true;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	stack<int> st;
	st.push(0);
	int ascOrder = 1;
	for (int i = 1; i <= n; i++) {
		int seqElement;
		cin >> seqElement;
		if (seqElement > st.top()) {
			for (; st.top() != seqElement; ascOrder++) {
				st.push(ascOrder);
				calculator[cal_idx++] = '+';
			}
			st.pop();
			calculator[cal_idx++] = '-';
		}
		else {
			if (st.top() != seqElement) {
				isSequence = false;
				break;
			}
			else {
				st.pop();
				calculator[cal_idx++] = '-';
			}
		}
	}
	if (isSequence) {
		for (int i = 0; i < cal_idx; i++) {
			cout << calculator[i] << '\n';
		}
	}
	else {
		cout << "NO" << '\n';
	}

}
