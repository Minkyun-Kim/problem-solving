#include <iostream>
using namespace std;
int main() {
	int n, sum=0;
	char arr[100];
	cin >> n;
	cin >> arr;
	for (int i = 0; i < n; i++) {
		
		sum += arr[i]-'0';
	}
	cout << sum << endl;
}