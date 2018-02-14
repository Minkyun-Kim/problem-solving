#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    sort(s.begin(), s.end(), greater<int>());
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        sum += s[i] - '0';
    }
    if(s[s.size()-1] == '0' && sum % 3 == 0)
        cout << s << '\n';
    else
        cout << -1 << '\n';
    return 0;
}
