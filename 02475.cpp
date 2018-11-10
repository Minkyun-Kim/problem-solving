#include <bits/stdc++.h>
using namespace std;

int main(){
    int ans = 0;
    for(int i = 0; i < 5; i++){
        int n;
        cin >> n;
        ans += n*n;
    }
    cout << ans%10 << '\n';
    return 0;

}
