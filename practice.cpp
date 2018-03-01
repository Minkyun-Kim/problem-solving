#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n, k, A, B;
    cin >> n >> k >> A >> B;
    vector<long long> v(n+1);
    for (int i = 2; i <= n; i++) {
        if (i%k == 0)
            v[i] = min(v[i - 1] + A, v[i / k] + B);
        else
            v[i] = v[i - 1] + A;
    }
    cout << v[n] << '\n';
    return 0;
}
