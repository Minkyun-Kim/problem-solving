#include <iostream>
#include <deque>
using namespace std;

int main() {
	int n;
	deque<int> q1, q2;

	cin >> n;
		for(int i=0;i<n;i++)
			q1.push_front(i+1);
		if (n != 1) {
			while (1) {
				q2.push_back(q1.back());
				q1.pop_back();
				if (q1.size() == 1)
					break;
				q1.push_front(q1.back());
				q1.pop_back();

			}
			while (!q2.empty()) {
				cout << q2.front() << " ";
				q2.pop_front();
			}
		}
	cout << q1.front() << endl;
	q1.pop_front();
}