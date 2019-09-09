#include <iostream> 
using namespace std;

int n, s;
int arr[20];
int answer;

void get(int sum, int idx) {
	if (sum == s) {
		if(idx != 0)
			answer++;
	}
	for (int i = idx; i < n; i++) {
		get(sum + arr[i], i+1);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	get(0, 0);
	cout << answer << '\n';
}
