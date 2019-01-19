#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s1, s2;
    char c;
    cin >> s1 >> c >> s2;

    if(c == '+'){
        if(s1.size() < s2.size()){
            string temp = s1;
            s1 = s2;
            s2 = temp;
        }
        if(s1.size() == s2.size()){
            s1[0] = '2';
            cout << s1 << '\n';
        }
        else{
            int pos = s1.size() - s2.size();
            s1[pos] = '1';
            cout << s1 << '\n';
        }
    }
    else if (c == '*'){
        int length = s1.size() + s2.size() - 2;
        string ans;
        ans.push_back('1');
        for(int i = 0; i < length; i++){
            ans.push_back('0');
        }
        cout << ans << '\n';
    }
    return 0;
}
