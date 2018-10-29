#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s;
    int n, flag = 0, ans = 0;
    cin >> s >> n;
    for(int i = 0; i < n; i++){
        string ring;
        cin >> ring;
        for(int j = 0; j < ring.length(); j++){
            if(ring[j] == s[0]){
                for(int k = 0; k < s.size(); k++){
                    if(j+k >= ring.length())
                        j -= ring.length();
                    if(ring[j+k] != s[k])
                        break;
                    if(k == s.size()-1){
                        ans++;
                        flag = 1;
                    }
                }
                if(flag = 1){
                    flag = 0;
                    break;
                }
            }           
        }
    }
    cout << ans << '\n';
    return 0;
}
