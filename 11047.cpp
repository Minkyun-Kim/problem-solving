#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int ans = 0;
    for(int i = n-1; i >=0; i--){
        ans += k/ a[i];
        k %= a[i];
    }

    /*
       while(k != 0){
        while(k <= v[i]){
            i--;
        }
        ans += k / v[i];
        k %= v[i];    
    }
    */
    cout << ans << '\n';
    return 0;
}
