#include <bits/stdc++.h>
using namespace std;

int arr[42];

int main(){
    for(int i = 0; i < 10; i++){
        int temp;
        cin >> temp;
        arr[temp%42] = true;
    }
    int ans = 0;
    for(int i = 0; i < 42; i++){
        if(arr[i] != 0)
            ans++;
    }
    cout << ans << '\n';
    return 0;
}
