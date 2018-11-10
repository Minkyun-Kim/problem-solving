#include <bits/stdc++.h>
using namespace std;

int main(){
    int n1, n2, ans = 0;
    cin >> n1 >> n2;
    int arr[3];
    arr[2] = n1*(n2/100);
    n2 -= (n2/100)*100;
    arr[1] = n1*(n2/10);
    n2 -=(n2/10)*10;
    arr[0] = n1*n2;
    ans = arr[0] + arr[1]*10 + arr[2]*100;
    cout << arr[0] << '\n';
    cout << arr[1] << '\n';
    cout << arr[2] << '\n';
    cout << ans << '\n';
    return 0;
}
