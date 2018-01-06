#include <iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, p;
    map<long long, int> m;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p;
        m[p]++;
    }
    int cnt = 0;
    long long ans = 0;
    for(auto &a : m){
        if(cnt < a.second){
            cnt = a.second;
            ans = a.first;
        }
        else if(a.second == cnt && a.first <ans)
            ans = a.first;
    }
    cout << ans << '\n';
    return 0;

}
