#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    int i;
    for(i = 0; i < s.size(); i++){
        if(s[i] == '-') //-기준으로 나눔. -앞은 양수 뒤는 음수로 간주하면됨.
            break;
    }
    int plus = 0, minus = 0;
    int tmp = 0;
    for(int j = 0; j < s.size(); j++){
        if(s[j] >= '0' && s[j] <= '9'){
            tmp *= 10;
            tmp += s[j] - '0';
        }
        else if(j <= i){   //+앞까진 양수로 더해줌
            plus += tmp;
            tmp = 0;
        }
        else if(j > i){// 나머진 음수로 간주
            minus += tmp;
            tmp = 0;
        }
    }
    if (i == s.size())
        plus += tmp;
    else
        minus += tmp;
    cout << plus-minus << '\n';
    return 0;
}
