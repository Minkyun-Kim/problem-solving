#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    int i, j;
    while(n--){
        cin >> i >> j;
        v.push_back({i, j});
    }
    
    sort(v.begin(), v.end(), [](pair<int, int> p1, pair<int, int> p2){
            if(p1.first < p2.first)
                return true;
            else if(p1.first == p2.first)
                return p1.second < p2.second;
            else
                return false;
                });
    for(auto it = v.begin(); it != v.end(); it++){
        cout<< it->first << ' ' << it->second << '\n';
    }
    return 0;
}   
