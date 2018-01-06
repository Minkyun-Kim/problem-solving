#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, ans = 1;
    cin >> n;
    if( n == 0)
        cout << 1 << '\n';
    else{
        for(int i = 1; i<=n; i++){
            ans *= i;
        }
        cout << ans << '\n';
    }
    return 0;
}
