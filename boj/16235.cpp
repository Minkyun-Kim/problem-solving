#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Tree {
public:
	int x;
	int y;
	int age;
	Tree() {
		x = -1;
		y = -1;
		age = -1;
	}
	Tree(int x, int y, int age) {
		this->x = x;
		this->y = y;
		this->age = age;
	}
};

bool comp(Tree t1, Tree t2) {
	if (t1.age < t2.age)
		return true;
	else
		return false;
}

int nutri[10][10];
int ground[10][10];
int n, m, k;
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector<Tree> v;
int ans;

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> nutri[i][j];
			ground[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		v.push_back(Tree(x - 1, y - 1, age));
	}
	while (k--) {
		sort(v.begin(), v.end(), comp);
		vector<Tree> die;
		vector<Tree> alive;
		vector<Tree> five;
		vector<Tree> birth;
		//봄 : 양분을 먹는다. 양분이 자기의 나이보다 작게 있다면 나무는 죽는다.
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].x;
			int y = v[i].y;
			int age = v[i].age;
			if (ground[x][y] >= v[i].age) {
				ground[x][y] -= v[i].age;
				age++;
				alive.push_back(Tree(x, y, age));
				if (age % 5 == 0)
					five.push_back(Tree(x, y, age));
			}
			else {
				die.push_back(Tree(x, y, age));
			}
		}
		//여름
		for (int i = 0; i < die.size(); i++) {
			int x = die[i].x;
			int y = die[i].y;
			int age = die[i].age;
			ground[x][y] += age / 2;
		}
		//가을
		for (int i = 0; i < five.size(); i++) {
			for (int j = 0; j < 8; j++) {
				int x = five[i].x + dx[j];
				int y = five[i].y + dy[j];
				if (x >= 0 && x < n && y >= 0 && y < n)
					birth.push_back(Tree(x, y, 1));
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ground[i][j] += nutri[i][j];
			}
		}
		v.clear();
		for (int i = 0; i < alive.size(); i++) {
			int x = alive[i].x;
			int y = alive[i].y;
			int age = alive[i].age;
			v.push_back(Tree(x, y, age));
		}
		for (int i = 0; i < birth.size(); i++) {
			int x = birth[i].x;
			int y = birth[i].y;
			int age = birth[i].age;
			v.push_back(Tree(x, y, age));
		}
		five.clear();
		die.clear();
		alive.clear();
		ans = v.size();
	}
	cout << ans << '\n';
	return 0;
}
