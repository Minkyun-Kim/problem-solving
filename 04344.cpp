#include <iostream>
using namespace std;
int main() {
	int c;
	cin >> c;
	double* avg = new double[c];
	double* rate = new double[c];
	for (int i = 0; i < c; i++) {
		int j, cnt = 0;
		cin >> j;
		double* test = new double[j];
		avg[i] = 0.;
		for (int k = 0; k < j; k++) {
			cin >> test[k];
			avg[i] += test[k];
		}
		avg[i] = avg[i] / j;
		for (int a = 0; a < j; a++) {
			if (test[a] > avg[i]) {
				cnt++;
			}
		}
		rate[i] =(double)cnt / j * 100;
		delete[]test;
	}
	cout << fixed;
	cout.precision(3);
	for (int i = 0; i < c; i++) {
		cout << rate[i] << "%" << endl;
	}
}