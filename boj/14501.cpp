#include <cstdio>
using namespace std;

int n;
int arr[16][2];
int ans;
int temp;

void work(int day) {
	if (day + arr[day][0] - 1 >= n) {
		if (day + arr[day][0] - 1 == n)
			temp += arr[day][1];
		ans = ans > temp ? ans : temp;
		if (day + arr[day][0] - 1 == n)
			temp -= arr[day][1];
		return;
	}
	temp += arr[day][1];
	for (int i = day+arr[day][0]; i <= n; i++) {
		work(i);
	}
	temp -= arr[day][1];
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	for (int i = 1; i <= n; i++) {
			work(i);
	}
	printf("%d\n", ans);

}
