#include <iostream>
#include <vector>
using namespace std;

struct Edge{
    int from;
    int to;
    int cost;
};

int INF = 2000000000;
int dist[501];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, w;
        cin >> n >> m >> w;
        vector<Edge> v;
        for(int i = 0; i < m + w; i++){
            int from, to, cost;
            cin >> from >> to >> cost;
            if( i < m ){
                v.push_back({from, to, cost});
                v.push_back({to, from, cost});
            }
            else
                v.push_back({from, to, -cost});
        }
        
        int cycle = false;
        dist[1] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2*m + w; j++){
                int from = v[j].from;
                int to = v[j].to;
                int cost = v[j].cost;
                if(dist[from] != INF && dist[to] > dist[from] + cost){
                    dist[to] = dist[from] + cost;
                    if(i == n-1){
                        cycle = true;
                    }
                }
            }
        }
        
        if(cycle == true){
            cout << "YES" << '\n';
        }
        else
            cout << "NO" << '\n';
        

        
    }

}
