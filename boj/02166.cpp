#include <cstdio>

typedef struct Point {
	long long x;
	long long y;
	Point operator-(Point A) {
		return{ x - A.x, y - A.y };
	}
}Point;

Point points[10001];

double ccw(Point a, Point b, Point c) {
	long long ans = a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - c.y*a.x;
	return (double)ans/2;
}

int main() {
	int n;
	scanf("%d", &n);
	int i;
	for (i= 0; i < n; i++) {
		scanf("%lld %lld",  &points[i].x, &points[i].y);
	}
	points[i] = points[0];
	double ans = 0.0;
	for (int i = 0; i < n; i++) {
		ans += ccw(points[0], points[i], points[i + 1]);
	}
	printf("%.1lf", ans> 0? ans : -1 * ans);

} 
