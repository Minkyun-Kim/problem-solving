#include <iostream>
#include <cstdio>
using namespace std;

int n, sum;
int arr[20][20];
bool player[20];
int diff = 210000000;
void clear() {
	for (int i = 0; i < n; i++) {
		player[i] = false;
	}
}
int getScore() {
	int score = 0;
	int opScore = 0;
	for (int i = 0; i < n; i++) {
		if (player[i] == true) {
			for (int j = 0; j < n; j++) {
				if (player[j] == true)
					score += arr[i][j];
			}
		}
		else {
			for (int j = 0; j < n; j++) {
				if (player[j] == false)
					opScore += arr[i][j];
			}
		}
	}
	return abs(opScore - score);
}
void dfs(int cnt, int who) {
	if (cnt == n / 2) {
		int score = getScore();
		if (diff > score)
			diff = score;
		return;
	}
	for (int i = who + 1; i < n; i++) {
		player[i] = true;
		dfs(cnt + 1, i);
		player[i] = false;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			sum += arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		clear();
		player[i] = true;
		dfs(1, i);
		player[i] = false;
	}
	printf("%d\n", diff);
}
