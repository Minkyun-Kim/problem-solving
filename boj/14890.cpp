#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int road[100][100];
int L, N;
int temp[100];
int cnt = 0;

void rowCopy(int a) {
	for (int i = 0; i < N; i++) {
		temp[i] = road[a][i];
	}
	return;
}
void colCopy(int a) {
	for (int i = 0; i < N; i++) {
		temp[i] = road[i][a];
	}
}

void isRoad() {
	int index = 0;
	for (int i = 0; i < N; i++) {
		if (temp[index] == temp[i])
			continue;
		if (abs(temp[index] - temp[i]) != 1)
			return;
		if (temp[index] < temp[i]) {
			if (i - index < L)
				return;
			index = i;
		}
		else {
			if (i + L -1 >= N)
				return;
			for (int j = i; j < i + L; j++) {
				if (temp[i] != temp[j])
					return;
			}
			if (temp[i + L - 1] < temp[i + L])
				return;
			else if (temp[i + L - 1] == temp[i + L]) {
				index = i + L;
				i = i + L - 1;
			}
			else {
				index = i + L - 1;
				i = i + L - 1;
			}
		}
	}
	cnt++;
	return;
}

int main() {
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &road[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		rowCopy(i);
		isRoad();
	}
	for (int i = 0; i < N; i++) {
		colCopy(i);
		isRoad();
	}
	printf("%d\n", cnt);
}
