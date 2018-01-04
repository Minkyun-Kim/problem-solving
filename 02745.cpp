#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string s;
    int n, ans = 0;
    cin >> s >> n;
    for(int i = 0; i < s.size(); i++){
        if(s[i] <= '9')
            ans += (int)(s[i] - '0');
        else
            ans += (int)(s[i]- 'A');
        if(i != s.size() - 1)
            ans *= n;
        else
            break;
    }
    cout << ans << '\n';
    return 0;

}
