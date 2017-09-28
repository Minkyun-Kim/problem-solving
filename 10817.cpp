#include <iostream>
using namespace std;
int main() {
	int arr[3];
	cin >> arr[0]>>arr[1]>>arr[2];
	int i = 0;
	for (int k = 0; k < 2; k++) {
		if (arr[i] > arr[i + 1]) {
			int temp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = temp¤±;
		}
		if (arr[i + 1] > arr[i + 2]) {
			int temp = arr[i + 2];
			arr[i + 2] = arr[i + 1];
			arr[i + 1] = temp;
		}
	}
	cout << arr[1] << endl;

}