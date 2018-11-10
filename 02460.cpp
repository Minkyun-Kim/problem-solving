#include <bits/stdc++.h>
using namespace std;

int main(){
    int ans = 0;
    int out, in, now=0;
    for(int i = 0; i < 10; i++){
        cin >> out >> in;
        now = now - out + in;
        if(ans < now)
            ans = now;
    }
    cout << ans << '\n';
    return 0;
}
