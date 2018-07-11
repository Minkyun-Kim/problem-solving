#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool check[200000];

int main(){
    
    while(true){
        int n, m;
        cin >> n >> m;
        if( n == 0 && m == 0 )
            break;
        for(int i = 1; i <= n; i++){
            check[i] = false;
        }
        vector<pair<int, int> > v[200000];
        int originCost = 0;
        for(int i = 0; i < m; i++){
            int from, to, cost;
            cin >> from >> to >> cost;
            v[from].push_back({-cost, to});
            v[to].push_back({-cost, from});
            originCost += cost;
        }
        check[0] = true;
        priority_queue<pair<int, int> > pq;
        for(int i = 0; i < v[0].size(); i++){
            pq.push(v[0][i]);
        }
        int totalCost = 0;
        while(!pq.empty()){
            int to = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();
            if(!check[to]){
                check[to] = true;
                totalCost += cost;
                for(int i = 0; i < v[to].size(); i++){
                    if(!check[v[to][i].second])
                         pq.push(v[to][i]);
                }
            }
        
            
        }
        cout << originCost - totalCost << '\n';


    }
    return 0;

}
