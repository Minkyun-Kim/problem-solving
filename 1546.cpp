#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	double* arr = new double[n];
	double m = 0;
	double avg=0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > m)
			m = arr[i];
	}
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] / m * 100;
		avg += arr[i];
	}
	cout << fixed;
	cout.precision(2);
	cout << avg / n << endl;
}