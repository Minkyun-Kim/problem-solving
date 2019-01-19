#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int time;
        cin >> time;
        string s;
        cin >> s;
        for(int i = 0; i <s.size(); i++){
            for(int j = 0; j < time; j++){
                cout << s[i];
            }
        }
        cout << '\n';
    }
    return 0;
}
