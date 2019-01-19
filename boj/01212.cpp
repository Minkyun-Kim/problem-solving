#include <iostream>
#include <string>
using namespace std;

int main(){
    string s8, s[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    cin >> s8;
    if(s8 == "0")
        cout<<"0" << '\n';
    else{
        if(s8[0] == '1')
            cout << 1;
        else if(s8[0] <'4')
            cout << s[s8[0]-'0'][1] << s[s8[0]-'0'][2];
        else
            cout<< s[s8[0]-'0'];
        for(int i = 1; i < s8.length(); i++){
            cout<< s[s8[i]-'0'];                
        }
    }
    cout<<'\n';
    return 0;
}
