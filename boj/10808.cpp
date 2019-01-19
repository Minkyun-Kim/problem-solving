#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i=97; i<123; i++){
        cout<< count(s.begin(),s.end(), i) << ' ';
    }
    cout << '\n';
    return 0;
}
