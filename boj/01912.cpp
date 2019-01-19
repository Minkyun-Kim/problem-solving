#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> d(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++){
        d[i] = a[i];
        if( i==0)
            continue;
        /*
           d[i-1]+a[i]랑 a[i]랑 비교해서 큰거 가져가기.
         */
        if(d[i] < d[i-1] + a[i])
            d[i] = d[i-1] + a[i];
    }
    int ans = d[0];
    for(int i = 1; i<n; i++)
        if(ans < d[i])
            ans = d[i];
    cout <<ans << '\n';
    return 0;
}
