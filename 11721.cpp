#include <iostream>
using namespace std;
int main() {
	char arr[100];
	cin >> arr;
	int n = 0;
	while (1) {
		for (int i = 0; i < 10; i++) {
			if (arr[n] == NULL)
				break;
			cout << arr[n];
			n++;
		}
		cout << endl;
		if (arr[n] == NULL)
			break;
	}
}