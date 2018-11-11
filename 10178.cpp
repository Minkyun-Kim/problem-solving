#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int candy, bro;
        cin >> candy >> bro;
        printf("You get %d piece(s) and your dad gets %d piece(s).\n", candy / bro, candy % bro);
    }
    return 0;
}
