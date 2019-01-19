#include <bits/stdc++.h>
using namespace std;

long long arr[101];
long long ans[101];
int main(){
    int n;
    long long sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    ans[1] = sum = arr[1];
    for(int i = 2; i <= n; i++){
        ans[i] = arr[i]*i-sum;
        sum += ans[i];
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
    

