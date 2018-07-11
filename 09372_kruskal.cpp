#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int parent[1001];

int find(int node){
    if(parent[node] == node)
        return parent[node];
    else
        return parent[node] = find(parent[node]);
}


void merge(int from, int to){
    int x = find(from);
    int y = find(to);
    parent[x] = y;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        
        for(int i = 1; i <= n; i++)
            parent[i] = i;

        vector<pair<int, int> > v(m);
        for(int i = 0; i < m; i++){
            cin >> v[i].first >> v[i].second;
        }

        int ans = 0;
        for(int i = 0; i < m; i++){
            int from = v[i].first;
            int to = v[i].second;
            if(find(from) != find(to)){
                merge(from, to);
                ans++;
            }
        }
        cout << ans << '\n';
        
    }

    return 0;
}
