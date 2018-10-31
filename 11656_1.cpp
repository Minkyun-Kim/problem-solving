#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    vector<string> v;
    string s;
    cin >> s;
    v.push_back(s);
    for(int i = 1; i < s.size(); i++){
        v.push_back(s.substr(i, s.size()));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << '\n';
    }
}
