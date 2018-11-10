#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    if(s.find('_') == -1){
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'A'){
                s.insert(i, '_');
                s[i+1] += 'a' - 'A';
            }
        }
    }
    else{
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '_'){
                s.erase(i--);
                s[i] -= 'a' - 'A';
            }
        }
    }
    cout << s << '\n';
}
