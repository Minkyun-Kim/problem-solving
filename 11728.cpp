#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v1(n);
    vector<int> v2(m);
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> v1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> v2[i];
    }
    int i = 0, j = 0;
    while (i < n && j < m){
        if(v1[i] < v2[j]){
            v.push_back(v1[i++]);
        }
        else{
            v.push_back(v2[j++]);
        }
    }
    if(i != n)
        while(i < n)
            v.push_back(v1[i++]);
    if(j != m)
        while(j < m)
            v.push_back(v2[j++]);
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << '\n';
    return 0;
}
