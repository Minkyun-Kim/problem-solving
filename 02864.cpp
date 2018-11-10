#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    string small1, small2;
    for(int i = 0; i < s1.size();i++){
        if(s1[i] == '5')
            s1[i] = '6';
        if(s1[i] == '6')
            small1.push_back('5');
        else
            small1.push_back(s1[i]);
    }
    for(int i = 0; i < s2.size();i++){
        if(s2[i] == '5')
            s2[i] = '6';
        if(s2[i] == '6')
            small2.push_back('5');
        else
            small2.push_back(s2[i]);
    }
    cout << stoi(small1) + stoi(small2) << ' ' <<stoi(s1) + stoi(s2)  << '\n';
    return 0;
}

