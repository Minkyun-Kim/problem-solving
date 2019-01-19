#include <iostream>
using namespace std;
int main() {
	int n, x, temp;
	int* arr;
	cin >> n >> x;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp < x) {
			arr[i] = temp;
		}
		else
			arr[i] = NULL;
		
	}
	for (int i = 0; i < n;i++) {
		if (arr[i]!=NULL) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}