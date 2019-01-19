#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s1, s2;
        int n1=0, n2;
        for(int i = 0; i < n; i++){
            cin >> s2 >> n2;
            if(n1 < n2){
                s1 = s2;
                n1 = n2;
            }
        }
            cout << s1 << '\n';
    }
    return 0;
}
