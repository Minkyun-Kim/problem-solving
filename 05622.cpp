#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] <= 'C')
            ans += 3;
        else if (s[i] <= 'F')
            ans += 4;
        else if (s[i] <= 'I')
            ans += 5;
        else if (s[i] <= 'L')
            ans += 6;
        else if (s[i] <= 'O')
            ans += 7;
        else if (s[i] <= 'S')
            ans += 8;
        else if (s[i] <= 'V')
            ans += 9;
        else
            ans += 10;
    }
    cout << ans << '\n';
    return 0;
}
