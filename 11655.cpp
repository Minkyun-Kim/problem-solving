#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    for (int i = 0; s[i]; i++){
        if(s[i]>= 65 && s[i] <= 90){
            if(s[i]>=78)
                s[i] -= 13;
            else
                s[i] += 13;
        }
        else if(s[i] >= 97 && s[i] <= 122){
            if(s[i] >=110)
                s[i] -= 13;
            else
                s[i] += 13;
        }
    }
    cout << s << '\n';
    return 0;
}
