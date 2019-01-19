#include <bits/stdc++.h>
using namespace std;

int main(){
    int sum=0, n;
    for(int i = 0; i < 4; i++){
        cin >> n;
        sum += n;
    }
    cout << sum/60 << '\n';
    cout << sum%60 << '\n';
    return 0;
}
