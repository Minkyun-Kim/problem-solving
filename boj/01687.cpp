#include <iostream>
#include <queue>
using namespace std;

bool arr[100001];

int main() {
	int n, k;
	cin >> n >> k;
	queue<pair<int, int> > q;

	q.push({ n, 0 });
	arr[n] = true;

	while (!q.empty()) {
		pair<int, int>  pr;
		pr = q.front();
		q.pop();
		if (pr.first == k) {
			cout << pr.second << '\n';
			break;
		}
		if (pr.first+1 <= 100000 && !arr[pr.first + 1]) {
			q.push({ pr.first + 1, pr.second + 1 });
			arr[pr.first + 1] = true;
		}
		if (pr.first-1 >= 0 && !arr[pr.first - 1]) {
			q.push({ pr.first - 1, pr.second + 1 });
			arr[pr.first - 1] = true;
		}
		if (pr.first*2 <= 100000 && !arr[pr.first * 2]) {
			q.push({ pr.first * 2, pr.second + 1 });
		}
	}

}
