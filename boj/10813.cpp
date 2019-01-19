#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin>> n >> m;
    vector<int> v;
    v.push_back(0);
    for(int i = 1; i <= n; i++){
        v.push_back(i);
    }
    int i, j;
    while(m--){
        cin >> i >> j;
        swap(v[i], v[j]);
    }
    auto it = v.begin() + 1;
    while(it != v.end()){
        cout << *it << ' ';
        it++;
    }
    cout << '\n';
    return 0;
}
