#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int sum = 0, score = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'O'){
                sum++;
                score += sum;
            }
            else{
                sum = 0;
            }
        }
        cout << score << '\n';
    }
    return 0;
}
