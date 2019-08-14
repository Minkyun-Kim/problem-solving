#include <iostream>
using namespace std;

const int start = 1048575;

int sbt[2100000];

void update(int idx, int value) {
	sbt[idx] += value;
	idx = idx >> 1;
	while (idx > 0) {
		sbt[idx] += value;
		idx = idx >> 1;
	}
}

int get(int index, int a) {
	while (index <= start) {
		sbt[index]--;
		if (a <= sbt[index << 1]) {
			index = index << 1;
		}
		else {
			a -= sbt[index << 1];
			index = (index << 1) + 1;
		}
	}
	sbt[index]--;//리프에서도 값을 빼줘야 하는데 깜빡함
	return index - start;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			//꺼내는 경우
			cin >> b;
			cout << get(1, b) << '\n';
		}
		else {
			//넣는경우 값을 업데이트
			cin >> b >> c;
			update(start + b, c);
		}
	}

}
