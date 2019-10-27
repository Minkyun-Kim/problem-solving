#include <iostream>
using namespace std;

bool prime[10001];
int t, n;

void initPrime() {
	for (int i = 0; i < 10001; i++) {
		prime[i] = true;
	}
}

void makePrime() {

	for (int i = 2; i <= 100; i++) {
		for (int j = i * i; j < 10001; j += i) {
			prime[j] = false;
		}
	}
}

int main() {
	cin >> t;
	initPrime();
	makePrime();
	while (t--) {
		cin >> n;
		for (int i = n/2; i >=2; i--) {
			if(prime[i] && prime[n-i] ){
				cout << i << ' ' << n - i << '\n';
				break;
			}
		}
	}
	
}
