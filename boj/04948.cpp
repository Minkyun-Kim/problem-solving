#include <iostream>
using namespace std;
int a[2 * 123456 + 1];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while (1) {
        cin >> n;
        if (n == 0)
            return 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 2; i*j <= 2 * n; j++) {
                a[i*j] = 1;
            }
        }
        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (a[i] == 0)
                cnt++;
        }
        cout << cnt << '\n';

    }
}
