#include <iostream>
#include <queue>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	deque<pair<int, int>> dq;
	int n, L;
	cin >> n >> L;
	for (int i = 0; i < n; i++) {
		int buf;
		cin >> buf;
		//범위 넘으면 삭제
		while(!dq.empty() && dq.front().second < i - L + 1)
			dq.pop_front();
		while (!dq.empty() && dq.back().first >= buf) {
			dq.pop_back();
		}
		dq.push_back({ buf, i });
		cout << dq.front().first << ' ';
	}
	cout << '\n';
}
