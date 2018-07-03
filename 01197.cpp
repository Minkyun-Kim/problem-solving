#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int parent[10001];

struct Edge{
    int from, to, cost;
    
    bool operator < ( Edge& e){
        return cost < e.cost;
    }
};

int find(int x){
    if(x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);
}

void merge(int x, int y){
    int top = find(x);
    parent[top] = find(y);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<Edge> v(m);
    for(int i = 0; i < m; i++){
        cin >> v[i].from >> v[i].to >> v[i].cost;
    }

    sort(v.begin(), v.end());
    
    int ans = 0;
    for(int i = 0; i < m; i++){
        Edge e = v[i];
        int x = find(e.from);
        int y = find(e.to);
        if(x != y){
            merge(x, y);
            ans += e.cost;
        }
    }
    cout << ans << '\n';
    return 0;

}
