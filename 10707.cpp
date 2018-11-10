#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, p;
    cin >> a >> b >> c >> d >>p;
    int x = 0, y = 0;
    x = a * p;
    if(p <= c)
        y = b;
    else
        y = b + (p-c)*d;
    if(x > y)
        cout << y << '\n';
    else 
        cout << x << '\n';
    return 0;
}
