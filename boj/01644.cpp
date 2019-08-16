#include <iostream>
#include <queue>
using namespace std;

int check[4000001];

int main() {
	int n;
	cin >> n;
	int ans = 0;
	int sum = 0;
	queue<int> q;
	for (int i = 2; i <= n; i++) {
		if (check[i])
			continue;
		if (i > n)
			break;
		for (int j = 1; j*i <= n;j++) {
			check[i*j] = 1;
		}
		q.push(i);
		sum += i;
		
		if (sum < n) {
			continue;
		}
		else if(sum > n){
			//sum > n
			while (sum > n) {
				sum -= q.front();
				q.pop();
			}
		}
		if (sum == n) {
			ans++;
		}
	}
	cout << ans << '\n';
}
