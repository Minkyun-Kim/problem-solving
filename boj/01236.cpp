#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
bool row[50], col[50];

int main() {
	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;
			scanf("%1c", &temp);
			if (temp == 'X') {
				row[i] = true;
				col[j] = true;
			}
		}
		cin.ignore();
	}

	int r = 0, c = 0;
	for (int i = 0; i < n; i++) {
		if (!row[i])
			r++;
	}
	for (int j = 0; j < m; j++) {
		if (!col[j])
			c++;
	}
	cout << (r > c ? r : c) << '\n';

}
