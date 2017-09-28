#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n >= 90 && n <= 100)
		cout << "A" << endl;
	else if (n >= 80 && n <= 89)
		cout << "B" << endl;
	else if (n >= 70 && n <= 79)
		cout << "C" << endl;
	else if (n >= 60 && n <= 69)
		cout << "D" << endl;
	else
		cout << "F" << endl;
}