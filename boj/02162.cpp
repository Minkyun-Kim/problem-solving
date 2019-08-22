#include <iostream>
using namespace std;

typedef struct Point {
	long long x;
	long long y;
	Point operator-(Point A) {
		return{ x - A.x, y - A.y };
	}
	bool operator<(Point A) {
		if (x == A.x)
			return y < A.y;
		return x < A.x;
	}
}Point;

Point points[3001][2];
int parent[3001];
int parentCnt[3001];



int _find(int a) {
	if (parent[a] == a)
		return a;
	else
		return parent[a] = _find(parent[a]);
}

void _union(int a, int b) {
	int parentA = _find(a);
	int parentB = _find(b);
	parent[parentA] = parent[parentB];
}

long long ccw(Point A, Point B) {
	long long ans = A.x * B.y - A.y * B.x;
	return ans > 0 ? 1 : ans < 0? -1:0;
}
long long ccw(Point A, Point B, Point C) {
	return ccw(B - A, C - A);
}

void _swap(Point &A, Point &B) {
	Point temp = A;
	A = B;
	B = temp;
}

bool isCrossed(Point A, Point B, Point C, Point D) {
	long long AB = ccw(A, B, C) * ccw(A, B, D);
	long long CD = ccw(C, D, A)* ccw(C, D, B);
	
	if (AB == 0 && CD == 0) {
		if (B < A)
			_swap(A, B);
		if (D < C) 
			_swap(C, D);
		if ((A < C&&B < C) || (D < A&&D < B))
			return false;
	}
	return AB <= 0 && CD <= 0;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld %lld %lld", &points[i][0].x, &points[i][0].y, &points[i][1].x, &points[i][1].y);
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (isCrossed(points[i][0], points[i][1], points[j][0], points[j][1])) {
				_union(i, j);
			}
		}
	}
	int maxUnion = 0;
	int groupCount = 0;
	for (int i = 1; i <= n; i++) {
		int prt = _find(i);
		parentCnt[prt]++;
		if (parentCnt[prt] == 1) 
			groupCount++;
		if (maxUnion < parentCnt[prt])
			maxUnion = parentCnt[prt];
	}
	printf("%d\n", groupCount);
	printf("%d\n", maxUnion);

}
