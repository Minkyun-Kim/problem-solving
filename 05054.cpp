#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, arr[100];
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr+n);
        cout << (arr[n-1] - arr[0])*2 << '\n';
    }
    return 0;
}
