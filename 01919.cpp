#include <iostream>
#include <string>
#include <vector>
using namespace std;
int st1[26], st2[26];

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    for(int i = 0; i < s1.size(); i++){
        st1[s1[i]-'a']++;
    }
    for(int i = 0; i < s2.size(); i++){
        st2[s2[i]-'a']++;
    }
    for(int i = 0; i < 26; i++){
        ans += abs(st1[i] - st2[i]);
    }
    cout << ans << '\n';
    return 0;
}
