#include <iostream>
#include <string>
using namespace std;

int n;
string s;

int main() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < n-1; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {
			if (s[j] != temp[j])
				s[j] = '?';
		}
	}
	cout<< s << '\n';

}
