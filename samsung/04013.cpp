#include <iostream>
#include <cstdio>
using namespace std;

#define gearSize 8
#define gearNum 4


int gear[4][8];
int front[4];
int rear[4];
int top[4];

int score();
void rotate(int, int);
void rotateGear(int, int);

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int K;
		cin >> K;
		//get gear input
		for (int i = 0; i < gearNum; i++) {
			for (int j = 0; j < gearSize; j++) {
				cin >> gear[i][j];
			}
		}
		//Set iterator
		for (int i = 0; i < gearNum; i++) {
			top[i] = 0;
			front[i] = (top[i] + 6) % 8;
			rear[i] = (top[i] + 2) % 8;
		}
		int answer = 0;
		for (int p = 0; p < K; p++) {
			int idx, direct;
			cin >> idx >> direct;
			rotate(idx - 1, direct);
		}
		cout << "#" << test_case << " " << score() << '\n';
	}
	return 0;
}

void rotate(int idx, int direct) {
	if (idx == 0) {
		if (gear[0][rear[0]] == gear[1][front[1]]) {
			rotateGear(0, direct);
		}
		else if (gear[1][rear[1]] == gear[2][front[2]]) {
			rotateGear(0, direct);
			rotateGear(1, -direct);
		}
		else if (gear[2][rear[2]] == gear[3][front[3]]) {
			rotateGear(0, direct);
			rotateGear(1, -direct);
			rotateGear(2, direct);
		}
		else {
			rotateGear(0, direct);
			rotateGear(1, -direct);
			rotateGear(2, direct);
			rotateGear(3, -direct);
		}
	}
	else if (idx == 1) {
		if (gear[0][rear[0]] == gear[1][front[1]]);
		else {
			rotateGear(0, -direct);
		}
		if (gear[1][rear[1]] == gear[2][front[2]])
			rotateGear(1, direct);
		else if (gear[2][rear[2]] == gear[3][front[3]]) {
			rotateGear(1, direct);
			rotateGear(2, -direct);
		}
		else {
			rotateGear(1, direct);
			rotateGear(2, -direct);
			rotateGear(3, direct);
		}
	}
	else if (idx == 2) {
		if (gear[2][rear[2]] == gear[3][front[3]]);
		else {
			rotateGear(3, -direct);
		}
		if (gear[1][rear[1]] == gear[2][front[2]])
			rotateGear(2, direct);
		else if (gear[0][rear[0]] == gear[1][front[1]]) {
			rotateGear(1, -direct);
			rotateGear(2, direct);
		}
		else {
			rotateGear(0, direct);
			rotateGear(1, -direct);
			rotateGear(2, direct);
		}
	}
	else if (idx == 3) {
		if (gear[2][rear[2]] == gear[3][front[3]]) {
			rotateGear(3, direct);
		}
		else if (gear[1][rear[1]] == gear[2][front[2]]) {
			rotateGear(2, -direct);
			rotateGear(3, direct);
		}
		else if (gear[0][rear[0]] == gear[1][front[1]]) {
			rotateGear(1, direct);
			rotateGear(2, -direct);
			rotateGear(3, direct);
		}
		else {
			rotateGear(0, -direct);
			rotateGear(1, direct);
			rotateGear(2, -direct);
			rotateGear(3, direct);
		}
	}
}

void rotateGear(int gnum, int direct) {
	if (direct == 1) {
		top[gnum] = (top[gnum] + 7) % 8;
		front[gnum] = (front[gnum] + 7) % 8;
		rear[gnum] = (rear[gnum] + 7) % 8;
	}
	else {
		top[gnum]++;
		top[gnum] %= 8;
		front[gnum]++;
		front[gnum] %= 8;
		rear[gnum]++;
		rear[gnum] %= 8;
	}
}
int score() {
	int score = 0;
	for (int i = 0; i < gearNum; i++) {
		int idx = top[i];
		if (gear[i][idx] == 1) {
			switch (i) {
			case 0:
				score += 1;
				break;
			case 1:
				score += 2;
				break;
			case 2:
				score += 4;
				break;
			case 3:
				score += 8;
				break;
			}

		}
	}
	return score;
}
