#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[6];
    int ans[6];
    int origin[6] = {1, 1, 2, 2, 2, 8};
    for(int i =0 ; i < 6; i++){
        cin >> arr[i];
        cout << origin[i] - arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}
