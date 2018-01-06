#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n+1);
    for(int i = 1; i <= n; i++){
        cin>> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(ans < v[i].second - i)
            ans = v[i].second - i;
    }
    cout << ans + 1 << '\n';
    return 0;
}
