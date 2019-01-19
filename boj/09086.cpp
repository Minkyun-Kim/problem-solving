#include <iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        cout << s[0] << s[s.size()-1] << '\n';
    }
    return 0;
}

