#include <iostream>
using namespace std;

int arr[100000];

long long _max(long long a, long long b) {
	return a > b ? a : b;
}
int _min(int a, int b) {
	return a > b ? b : a;
}

long long getArea(int left, int right) {
	if (left == right)
		return arr[left];
	int mid = (right - left) / 2 + left;
	long long ret = _max(getArea(left, mid), getArea(mid + 1, right));
	int le = mid;
	int ri = mid + 1;
	int height = _min(arr[le], arr[ri]);
	ret = _max(ret, height * 2);
	while (left < le || ri < right) {
		if (ri < right && (le == left || arr[ri + 1] > arr[le - 1])) {
			ri++;
			height = _min(height, arr[ri]);
		}
		else {
			le--;
			height = _min(height, arr[le]);
		}
		ret = _max(ret, (long long)height * (ri - le + 1));
	}
	return ret;

}

int main() {
	while (1) {
		int n;
		cin >> n;
		if (!n)
			break;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << getArea(0, n-1) << '\n';
	}
}
