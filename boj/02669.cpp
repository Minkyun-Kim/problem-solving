#include <bits/stdc++.h>
using namespace std;

bool arr[101][101];

int main(){
    for(int i = 0; i < 4; i++){
        int xl, yl, xr, yr;
        cin >> xl >> yl >> xr >> yr;
        for(int j = xl; j < xr; j++){
            for(int k = yl; k < yr; k++){
                arr[j][k] = true;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            if(arr[i][j] == true)
                ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}

