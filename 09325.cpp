#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
       int ans = 0; 
       int car;
       cin >> car;
       ans += car;
       int opt;
       cin >> opt;
       while(opt--){
           int num, cost;
           cin >> num >> cost;
           ans += num*cost;
       }
       cout << ans << '\n';
    }
    return 0;
}
