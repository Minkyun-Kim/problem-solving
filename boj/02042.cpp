#include <iostream>
using namespace std;

int input[10000001];
long long sbt[25000001];

int p = 1;

long long getSum(int index, int left, int right, int first, int end) {
	//cout << "left: " << left << ' ' << "right: " << right << ' ' << "first: " << first << ' ' << "end: " << end << '\n';
	//범위를 아예 벗어나면 탈출한다(겹치는 부분이 조금이라도 없기 때문)
  if (end <left || first > right) return 0;
  //조금 겹치긴 하는데 더 세부로 나뉘어져야 함
  //한쪽이라도 큰 경우
	if (left < first || right > end) {
		int mid = (left + right) / 2;
		return getSum(index * 2, left, mid, first, end) + getSum(index * 2 + 1, mid + 1, right, first, end);
	}
  //위 두 케이스를 제외하면 아예 포함되어버리니 바로 해당 배열 리턴하면 됨
	else 
    return sbt[index];
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int i = 0;
	for (; i < n; i++) {
		cin >> input[i];
	}
	//세그트리 초기화
	while (p < i)
		p = p << 1;
	for (int j = p; j < p + i; j++) {
		sbt[j] = input[j-p];
	}
	for (int j = p- 1; j > 0; j--) {
		sbt[j] = sbt[j * 2] + sbt[j * 2 + 1];
	}

	int count = m + k;
	for (i = 0; i < count; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		/*
		for (int j = 1; j <= 15; j++) {
			cout << sbt[j] << ' ';
		}
		cout << '\n';
		*/
		if (a == 1) {
			//b번째를 c로 교체
			int idx = p + b - 1;
			sbt[idx] = c;
			while (idx > 0) {
				if (idx % 2 == 0) {
					sbt[idx / 2] = sbt[idx] + sbt[idx + 1];
				}
				else {
					sbt[idx / 2] = sbt[idx] + sbt[idx -1];
				}
				idx = idx >> 1;
			}

		}
		else if (a == 2) {
			//b부터 c까지 출력
			cout << getSum(1, 1, p, b, c) << '\n';
		}
	}

}
