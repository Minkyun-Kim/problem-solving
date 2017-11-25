#include <iostream>
using namespace std;

int selfnum(int n) {
	int num=n;
	if (n == 10000) {
		return 10001; }
	if (n >= 1000) {
		num += n / 1000;
		n = n - n / 1000 * 1000;
	}
	if (n >= 100) {
		num += n / 100;
		n = n - n / 100 * 100;
	}
	if (n >= 10) {
		num += n / 10;
		n = n - n / 10 * 10;
	}
	num += n;
	return num;
}
int main() {
	int* arr=new int[10036];
	for (int i = 1; i <= 10000; i++) {
		arr[selfnum(i)] = 1;
	}
	for (int i = 1; i <= 10000; i++) {
		if (arr[i] != 1) {
			cout << i << endl;
		}
	}
}