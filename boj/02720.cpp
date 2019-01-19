#include <bits/stdc++.h>
using namespace std;

int arr[4];
int main(){
    int  t;
    cin >> t;
    while(t--){
        int cent;
        cin >> cent;
        memset(arr, 0, sizeof(arr));
        if(cent >= 25){
            arr[0] = cent/25;
            cent -= arr[0] *25;
        }
        if(cent >= 10){
            arr[1] = cent/10;
            cent -= arr[1]*10;
        }
        if(cent >= 5){
            arr[2] = cent/5;
            cent -= arr[2]*5;
        }
        arr[3] = cent;
        for(int i = 0; i < 4; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
