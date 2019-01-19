#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int cost[101][101];
    fill(cost, cost + 101 * 101, 100001);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to >> cost[from][to];
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }
}
