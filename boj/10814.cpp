#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n, age;
    vector<pair<int, string> > v;
    string name;
    cin >> n;
    while(n--){
        cin >> age >> name;
        v.push_back({age, name});
    }
    stable_sort(v.begin(), v.end(), [](pair<int, string> p1, pair<int, string> p2){
                return p1.first < p2.first;
                });
    for(auto it = v.begin(); it != v.end(); it++){
        cout << it->first << ' ' << it->second << '\n';
    }
    return 0;   
}
