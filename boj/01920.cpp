#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100000];

int biSearch(int left, int right, int ans) {
	int lo = left;
	int hi = right;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (arr[mid] == ans) {
			return 1;
		}
		else {
			if (arr[mid] < ans) {
				lo = mid + 1;
			}
			else {
				hi = mid-1;
			}
		}
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int _find;
		scanf("%d", &_find);
		cout << biSearch(0, n-1, _find) << '\n';
	}
}
