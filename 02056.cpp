#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[10001];
int ind[10001];
int work[10001];
int d[10001];//해당 작업까지 걸리는 시간을 기록

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1; i <= n; i++) {
        cin >> work[i];
        int cnt;
        cin >> cnt;
        for (int j=0; j<cnt; j++) {
            int x;
            cin >> x;
            a[x].push_back(i);
            ind[i] += 1;
        }
    }
    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (ind[i] == 0) {
            q.push(i);
            d[i] = work[i];
        }
    }
    for (int k=0; k<n; k++) {
        int x = q.front();
        q.pop();
        for (int i=0; i<a[x].size(); i++) {//해당 노드에서 갈 수 있는 모든 노드에 대하여
            int y = a[x][i];
            ind[y] -= 1;
            if (d[y] < d[x]+work[y]) {
                d[y] = d[x]+work[y];
            }
            if (ind[y] == 0) {
                q.push(y);
            }
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (ans < d[i]) {
            ans = d[i];
        }
    }
    cout << ans << '\n';
    return 0;
}
