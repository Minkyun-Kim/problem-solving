#include <iostream>
#include <vector>
using namespace std;
vector<int> v[1001];
int check[1001];

void dfs(int node){
    check[node] = 1;
    for(int i = 0; i < v[node].size(); i++){
        int next = v[node][i];
        if(check[next] == 0)
            dfs(next);
    }    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    int comp = 0;
    for(int i = 1; i <= n; i++){
        if(check[i] == 0){
            dfs(i);
            comp++;
        }
    }
    cout << comp << '\n';
    return 0;
}
