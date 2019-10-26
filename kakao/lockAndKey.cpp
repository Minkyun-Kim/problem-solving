#include <vector>
#include <string>
using namespace std;

void rotate(vector < vector<int>> & v) {
	vector<vector<int>> temp(v.size(), vector<int>(v.size()));
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			temp[j][v.size() - 1 - i] = v[i][j];
		}
	}
	v = temp;
}

bool isUnlocked(vector<vector<int>>& v, int size, int startPos) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (v[i+startPos][j+startPos] != 1) {
				return false;
			}
		}
	}
	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int bigSize = lock.size() + (key.size() - 1)*2;
	int startPos = key.size() - 1;
	vector<vector<int>> bigLock(bigSize, vector<int>(bigSize));
	for (int i = 0; i < lock.size(); i++) {
		for (int j = 0; j < lock.size(); j++) {
			bigLock[i + startPos][j + startPos] = lock[i][j];
		}
	}
	vector<vector<int>> v(bigSize, vector<int>(bigSize));
	for (int t = 0; t < 4; t++) {
		for (int i = 0; i <= bigSize - key.size(); i++) {
			for (int j = 0; j <= bigSize - key.size(); j++) {
				v.clear();
				v.resize(bigSize, vector<int>(bigSize));
				v = bigLock;
				for (int p = 0; p < key.size(); p++) {
					for (int q = 0; q < key.size(); q++) {
						v[i + p][j + q] += key[p][q];
					}
				}
				if (isUnlocked(v, lock.size(), startPos)) {
					return true;
				}

			}
		}
		rotate(key);
	}
	return false;
}
