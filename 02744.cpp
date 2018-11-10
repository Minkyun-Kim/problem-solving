#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size();i++){
        if(s[i] < 'a')
            s[i] += ('a'-'A');
        else
            s[i] -= ('a'-'A');
    }
    cout << s << '\n';
    return 0;
}
