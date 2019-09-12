#include <iostream>
using namespace std;

char s1[51], s2[51];
int _strlen(char s[]) {
	int len = 0;
	while (s[len] != '\0')
		len++;
	return len;
}

int main() {
	cin >> s1 >> s2;
	int s1Size = _strlen(s1);
	int s2Size = _strlen(s2);
	int diff = 50;
	for (int i = 0; i <= s2Size - s1Size; i++) {
		int temp = 0;
		for (int j = 0; j < s1Size; j++) {
			if (s1[j] != s2[j + i])
				temp++;
		}
		if (diff > temp)
			diff = temp;
	}
	cout << diff << '\n';

}
