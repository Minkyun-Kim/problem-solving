#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, arr[3];
    cin >> n;
    if(n == 2){
        cin >> arr[0] >> arr[1];
        sort(arr, arr+2);
        for(int i = 1; i <= arr[0]; i++){
            if(arr[0] % i == 0 && arr[1] % i == 0){
                cout << i << '\n';
            }
        }
    }
    else{
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr+3);
        for(int i = 1; i <= arr[0] ; i++){
            if(arr[0] % i == 0 && arr[1] % i == 0 && arr[2] %i== 0){
                cout << i << '\n';
            }
        }
    }
    return 0;
}
