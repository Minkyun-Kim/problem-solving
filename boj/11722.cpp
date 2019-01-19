#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> d(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = n; i>=1; i--){
        d[i] = 1;
        for(int j = i+1; j<=n;j++){
            if(a[i] > a[j] && d[i] < d[j] +1)
                d[i] = d[j] +1;
        }
    }
    int ans = d[1];
    for(int i = 2; i <= n; i++){
        if(ans < d[i])
            ans = d[i];
    }
    cout << ans << '\n';
    return 0;
}
