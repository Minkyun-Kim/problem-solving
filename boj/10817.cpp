#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int i, j, k;
    cin >> i >> j >> k;
    cout << (i+j+k) - min({i, j, k}) - max({i, j, k}) << '\n';
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int i, j, k;
    cin >> i>> j >> k;
    vector<int> v;
    v.push_back(i);
    v.push_back(j);
    v.push_back(k);
    sort(v.begin(), v.end());
    cout << v[1] << '\n';
    return 0;
}
*/
