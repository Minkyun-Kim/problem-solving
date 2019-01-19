#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s1, s2, del;
        cin >> s1 >> s2;
        del = s2;
        int flag = 0;
        if(s1.size() != s2.size())
            cout <<s1 << " & "<<s2 <<" are NOT anagrams.\n";
        else{
            for(int i = 0; i < s1.size(); i++){
                for(int j = 0; j < s2.size(); j++){
                    if(s1[i] == s2[j]){
                        s2[j] = 0;
                        break;
                    }
                    if(j == s2.size()-1){
                        cout <<s1 << " & "<<del <<" are NOT anagrams.\n";
                        flag = 1;
                    }
                }
            }
            if(flag == 0){
                cout <<s1 << " & "<<del <<" are anagrams.\n";
            }
        }
    }
    return 0;
}
