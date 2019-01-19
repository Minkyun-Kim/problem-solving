#include <bits/stdc++.h>
using namespace std;

bool arr[101];

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        memset(arr, false, sizeof(arr));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j*i <= n; j++){
                if(arr[i*j] == true)
                    arr[i*j] = false;
                else
                    arr[i*j] = true;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(arr[i] == true)
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}

