#include <iostream>
#include <string>
using namespace std;

int n;
string result[50];
bool same[50];

void init() {
	for (int i = 0; i < 50; i++) {
		same[i] = true;
	}
}

int main() {
	init();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> result[i];
		for(int j = 0; j < i; j++){
			for (int k = 0; k < result[i].length(); k++) {
				if (result[i][k] != result[j][k]) {
					same[k] = false;
				}
			}
		}

	}
	for (int i = 0; i < result[0].length(); i++) {
		if (same[i] == true)
			cout << result[0][i];
		else
			cout << "?";
	}
	cout << '\n';

}
