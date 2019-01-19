#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool check[100001];
vector<pair<int, int> > v[100001];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({-cost, to});
        v[to].push_back({-cost, from});
    }
    priority_queue<pair<int, int> > pq;

    for(int i = 0; i < v[1].size(); i++){
        pq.push(v[1][i]);
    }
    check[1] = true;
    priority_queue<int> road;
    while(!pq.empty()){
        int to = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(!check[to]){
            check[to] = true;
            road.push(cost);
            for(int i = 0; i < v[to].size(); i++){
                if(!check[v[to][i].second])
                    pq.push(v[to][i]);
            }
        }
    }
    road.pop();
    int ans = 0;
    while(!road.empty()){
        ans += road.top();
        road.pop();
    }
    cout << ans << '\n';
    return 0;

}
