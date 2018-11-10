#include <bits/stdc++.h>
using namespace std;

int main(){
    int L, P;
    cin >> L >> P;
    int num = L*P;
    int arr[5];
    for(int i = 0; i < 5;i++){
        cin >> arr[i];
        arr[i] -= num;
        cout << arr[i] <<' ';
    }
    cout << '\n';
    return 0;
}
