#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        printf("Case %d: %d\n", i, a+b);
    }
    return 0;
}
