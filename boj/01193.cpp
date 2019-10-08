#include <iostream>
using namespace std;


int main() {
	int n;
	cin >> n;

	int acc = 1;
	int i = 1;
	while (n >= acc+i) {
		acc += i;
		i++;
	}
	int diff = n - acc;
	int mom = i;
	int son = 1;
	mom -= diff;
	son += diff;
	if (i % 2 == 0) {
		cout << son << '/' << mom << '\n';
	}
	else {
		cout << mom << '/' << son << '\n';
	}
	
}
