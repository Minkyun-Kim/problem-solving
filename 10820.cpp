#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        int upper = 0, lower = 0, number = 0, blank = 0;
        for(auto x : s){
            if(x >= 48 && x <= 57)
                number++;
            else if(x >= 65 && x <= 90)
                upper++;
            else if(x >= 97 && x <= 122)
                lower++;
            else if( x ==' ')
                blank++;
        }
        cout << lower << ' ' << upper << ' ' << number << ' ' << blank << '\n';
    }
    return 0;
}
