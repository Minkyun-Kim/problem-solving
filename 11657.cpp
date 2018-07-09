#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge{
    int from;
    int to;
    int cost;
};

int dist[501];
int inf = 1000000000;


int main(){
    int n, m;
    cin >> n >> m;
    vector<Edge> v(m);
    for(int i = 0; i < m; i++){
        cin >> v[i].from >> v[i].to >> v[i].cost;
    }

    for(int i = 1; i <= n; i++){
        dist[i] = inf;
    }
    dist[1] = 0;
    bool cycle_check = false;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++) {
            int from = v[j].from;
            int to = v[j].to;
            int cost = v[j].cost;
            if(dist[from] != inf && dist[to] > dist[from] + cost){
                dist[to] = dist[from] + cost;
                if(i == n){
                    cycle_check = true;

                }
            }
        }
    }
    
    if(cycle_check == true){
        cout << -1 << '\n';
    }
    else{
        for(int i = 2; i <= n; i++){
            if(dist[i] != inf )
                cout << dist[i] << '\n';
            else
                cout << -1 << '\n';
        }
    }



}
