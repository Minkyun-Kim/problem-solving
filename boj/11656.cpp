#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s[1000];
    cin >> s[0];
    int len = s[0].length();
    for(int i = 1; i < len ; i++)
        s[i] = s[0].substr(i,len);
    sort(s, s+len);
    for(int i = 0; i < len; i++)
        cout<< s[i] << endl;
    return 0;
}
