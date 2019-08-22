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

Point points[4];
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
bool isVertical(Point A, Point B, Point C, Point D) {
	Point v1 = { B.x - A.x, B.y - A.y };
	Point v2 = { D.x - C.x, D.y - C.y };

	if ((v1.x*v2.x + v1.y*v2.y) == 0)
		return true;
	else
		return false;
}
bool isLength(Point A, Point B, Point C, Point D) {
	int len1 = (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y);
	int len2 = (C.x - D.x)*(C.x - D.x) + (C.y -D.y)*(C.y - D.y);
	if (len1 == len2)
		return true;
	else
		return false;
}
bool isCenter(Point A, Point B, Point C, Point D) {
	if ((A.x + B.x) == (C.x + D.x) && (A.y + B.y) == (C.y + D.y))
		return true;
	else
		return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 4; i++) {
			cin >> points[i].x >> points[i].y;
		}
		int flag = 0;
		if (isCrossed(points[0], points[1], points[2], points[3])) {
			if (isVertical(points[0], points[1], points[2], points[3])) {
				if (isLength(points[0], points[1], points[2], points[3])) {
					if (isCenter(points[0], points[1], points[2], points[3])) {
						flag = 1;
					}
				}
			}
		}
		else if (isCrossed(points[0], points[2], points[1], points[3])) {
			if (isVertical(points[0], points[2], points[1], points[3])) {
				if (isLength(points[0], points[2], points[1], points[3])) {
					if (isCenter(points[0], points[2], points[1], points[3])) {
						flag = 1;
					}
				}
			}
		}
		else if (isCrossed(points[0], points[3], points[1], points[2])) {
			if (isVertical(points[0], points[3], points[1], points[2])) {
				if (isLength(points[0], points[3], points[1], points[2])) {
					if (isCenter(points[0], points[3], points[1], points[2])) {
						flag = 1;
					}
				}
			}
		}
		cout << flag << '\n';
	}

}
