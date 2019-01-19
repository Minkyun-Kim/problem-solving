#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v(20);
    for(int i = 0; i < 20; i++)
        cin >> v[i];
    sort(v.begin(), v.begin() + 10);
    sort(v.begin()+10, v.begin()+20);
    cout << v[7] + v[8] + v[9] << ' ' << v[17] + v[18] + v[19] << '\n';
    return 0;
}
