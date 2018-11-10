#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a < b)
        return gcd(a, b%a);
    if(b==0)
        return a;
    gcd(b, a%b);
}
int arr[101];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i < n; i++){
        int g = gcd(arr[0], arr[i]);
        cout << arr[0]/g <<'/' << arr[i]/g <<'\n';
    }
    return 0;
}
