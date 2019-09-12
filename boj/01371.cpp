#include <iostream>
#include <cstdio>
using namespace std;

char s[5000];
int alpha[26];
int main() {
	int n = 0;
	while (fgets(s, 5000, stdin) != NULL) {
		for(int i = 0; s[i] != NULL; i++){
			if (s[i] >= 'a' && s[i] <= 'z') {
				alpha[s[i] - 'a']++;
			}
		}
	}
	int max = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] > max)
			max = alpha[i];
	}
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == max) {
			cout << (char)(i + 'a') ;
		}
	}
	cout << '\n';
}
