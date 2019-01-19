#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(i+1 < s.size() && s[i] == 'c' && s[i+1] == '='){
            i++;
            ans++;
        }
        else if (i+1 < s.size() && s[i] == 'c' && s[i+1] == '-'){
            i++;
            ans++;
        }
        else if (i+2 < s.size() && s[i] == 'd' && s[i+1] == 'z' && s[i+2] == '='){
            i += 2;
            ans++;
        }
        else if (i+1 < s.size() && s[i] == 'd' && s[i+1] == '-'){
            i++;
            ans++;
        }
        else if (i+1 < s.size() && s[i] == 'l' && s[i+1] == 'j'){
            i++;
            ans++;
        }
        else if(i+1 < s.size() && s[i] == 'n' && s[i+1] == 'j'){
            i++;
            ans++;
        }
        else if (i+1 < s.size() && s[i] == 's' && s[i+1] == '='){
            i++;
            ans++;
        }
        else if (i+1 < s.size() && s[i] == 'z' && s[i+1] == '='){
            i++;
            ans++;
        }
        else
            ans++;
    }
    cout << ans << '\n';
    return 0;
}
