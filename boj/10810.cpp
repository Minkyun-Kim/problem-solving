#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    while( m-- ){
        int i, j, k;
        cin >> i >> j >> k;
        fill(v.begin() + i, v.begin() + j + 1, k);
    }
    for( int i=1; i <= n; i++)
        cout<<v[i] << ' ';
    cout<< '\n';
    return 0;
}
