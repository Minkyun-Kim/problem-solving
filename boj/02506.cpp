#include <bits/stdc++.h>
using namespace std;

int arr[2][101];
int main(){
    int n, ans = 0;;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[0][i];
        if(arr[0][i]==1){
            arr[1][i] = arr[1][i-1]+1;
            ans += arr[1][i];
        }
    }
    cout << ans << '\n';
    return 0;
}
       
