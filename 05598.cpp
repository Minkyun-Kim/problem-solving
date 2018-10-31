#include <iostream>
#include <vector>
#include <string>
using namespace std;

char trans[29] = {'X','Y','Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W'};

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        s[i] = trans[s[i]-'A'];
    }
    cout << s << '\n';
    return 0;
}
