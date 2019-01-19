#include <cstdio>
void solve(int n, int x, int y) {
    if (n == 0) return;
    solve(n - 1, x, 6 - x - y);//x+y+z=6이고 n을 x에서 y로 옮기려면 n-1개를 x, y가 아닌 곳 즉 6에서 x자리값과 y자리값을 빼야함
    printf("%d %d\n", x, y);
    solve(n - 1, 6 - x - y, y);
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", (1 << n) - 1);
    solve(n, 1, 3);
    return 0;
}
