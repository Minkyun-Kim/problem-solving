#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    while( n >= 2 && m >= 1 && m+n >= k+3){
        ans += 1;
        n -= 2;
        m -= 1;
    }
    cout << ans << '\n';
    return 0;
}
