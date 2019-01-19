#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            ans += i+j;
        }
    }
    cout << ans << '\n';
    return 0;
}
