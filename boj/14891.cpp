#include <cstdio>
#include <algorithm>
using namespace std;

int gear[4][8];
int k;
int ans;
int check[4];

void realTurn() {
	for (int i = 0; i < 4; i++) {
		if (check[i] == 1) {
			int temp = gear[i][7];
			for (int j = 7; j > 0; j--) {
				gear[i][j] = gear[i][j-1];
			}
			gear[i][0] = temp;
		}
		if (check[i] == -1) {
			int temp = gear[i][0];
			for (int j = 0; j < 7; j++) {
				gear[i][j] = gear[i][j + 1];
			}
			gear[i][7] = temp;
		}
	}
}

void turn(int g) {
	if (g == 0) {
		if (gear[g][2] != gear[g+1][6] && check[g+1] == 0) {
			check[g + 1] = -check[g];
			turn(g + 1);
		}
	}
	else if (g == 3) {
		if (gear[g][6] != gear[g - 1][2] && check[g-1] == 0) {
			check[g - 1] = -check[g];
			turn(g - 1);
		}
	}
	else {
		if (gear[g - 1][2] != gear[g][6] && check[g-1] == 0) {
			check[g - 1] = -check[g];
			turn(g - 1);
		}
		if (gear[g + 1][6] != gear[g][2] && check[g+1] == 0) {
			check[g + 1] = -check[g];
			turn(g + 1);
		}
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &gear[i][j]);
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int g, d;
		for (int j = 0; j < 4; j++) {
			check[j] = 0;
		}
		scanf("%d %d", &g, &d);
		check[g - 1] = d;
		turn(g-1);
		realTurn();
	}

	if (gear[0][0] == 1) {
		ans += 1;
	}
	if (gear[1][0] == 1) {
		ans += 2;
	}
	if (gear[2][0] == 1) {
		ans += 4;
	}
	if (gear[3][0] == 1) {
		ans += 8;
	}
	printf("%d\n", ans);
}
