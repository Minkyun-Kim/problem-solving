#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int c = 100, s = 100;
    while(n--){
        int n1, n2;
        cin >> n1 >> n2;
        if(n1 < n2)
            c-=n2;
        else if(n1>n2)
            s -= n1;
    }
    cout << c << '\n' << s << '\n';
    return 0;
}
