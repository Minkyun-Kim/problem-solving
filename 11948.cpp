#include <bits/stdc++.h>
using namespace std;

int main(){
    int sum = 0, arr[6];
    for(int i = 0; i < 6; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr+4);
    sum -= arr[0];
    sort(arr+4, arr+6);
    sum -= arr[4];
    cout << sum << '\n';
    return 0;
}
