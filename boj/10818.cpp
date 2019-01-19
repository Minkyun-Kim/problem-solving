#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n;
    vector<int> v;
    while(n--){
        cin>>m;
        v.push_back(m);
    }
    auto it = minmax_element(v.begin(), v.end());
    cout << *it.first << ' ' << *it.second << '\n';
    return 0;
}
