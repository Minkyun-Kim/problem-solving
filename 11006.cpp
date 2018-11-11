#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << 2*b -a << ' ' << b - (2*b-a) <<'\n';
    }
    return 0;
}
