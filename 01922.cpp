#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > v[1001];
bool check[1001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({to, cost});
        v[to].push_back({from, cost});
    }

    priority_queue<pair<int, int> > pq;
    check[1] = true;
    for(int i = 0; i < v[1].size(); i++){
        pq.push({-v[1][i].second, v[1][i].first});
    }
    
    int ans = 0;
    while(!pq.empty()){
        pair<int, int> to = pq.top();
        pq.pop();
        if(check[to.second]) 
            continue;
        check[to.second] = true;
        ans += -to.first;
        for(int i = 0; i < v[to.second].size(); i++){
            pq.push({-v[to.second][i].second, v[to.second][i].first});
        }
    }

    cout << ans << '\n';
    return 0;

}
