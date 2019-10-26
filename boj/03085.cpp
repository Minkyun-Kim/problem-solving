#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char board[51][51];
int n;

int _max(int a, int b) {
	return a > b ? a : b;
}

int check() {
	int longest = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (board[i][j] == board[i][j + 1]) {
				cnt++;
			}
			else {
				longest = longest > cnt ? longest : cnt;
				cnt = 1;
			}
			longest = longest > cnt ? longest : cnt;
		}
	}
	for(int i = 0; i < n; i++){
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (board[j][i] == board[j + 1][i]) {
				cnt++;
			}
			else {
				longest = longest > cnt ? longest : cnt;
				cnt = 1;
			}
			longest = longest > cnt ? longest : cnt;
		}
	}	
	return longest;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	int candyCnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
				swap(board[i][j], board[i + 1][j]);
				candyCnt = _max(candyCnt, check());
				swap(board[i][j], board[i + 1][j]);
				swap(board[i][j], board[i][j + 1]);
				candyCnt = _max(candyCnt, check());
				swap(board[i][j], board[i][j + 1]);
		}
	}
	cout << candyCnt << '\n';
}
