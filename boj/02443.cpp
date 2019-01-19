#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, minus;
    cin >> n;
    minus = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            cout << ' ';
        }
        for(int j = 0; j < minus*2-1; j++){
            cout <<"*";
        }
        minus--;
        cout << '\n';
    }
    return 0;
}
