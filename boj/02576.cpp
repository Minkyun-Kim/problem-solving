#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[7];
    int cnt = 0;
    int sum = 0;
    for(int i = 0; i < 7; i++){
        cin >> arr[cnt];
        if(arr[cnt]%2 ==1){
            sum += arr[cnt];
            cnt++;
        }
    }
    if(cnt == 0){
        cout << -1 << '\n';
        return 0;
    }
    sort(arr, arr+cnt);
    cout << sum << '\n';
    cout << arr[0] << '\n';
    return 0;
}
