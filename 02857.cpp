#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s;
    vector<int> v;
    for(int k = 0; k < 5; k++){
        cin >> s;
        for(int i = 0; i < s.size()-2; i++){
            if(s[i] != 'F')
                continue;
            if(s[i+1] == 'B' && s[i+2] == 'I'){
                v.push_back(k+1);
                break;
            }
        }
    }
    if(v.size() == 0){
        cout << "HE GOT AWAY!"<< '\n';
    }
    else{
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << ' ';
    }
    return 0;
}
