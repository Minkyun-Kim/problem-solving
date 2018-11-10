#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > v[1001];
bool check[1001];
int dist[1001];
priority_queue<pair<int, int> > pq;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int from, to cost;
        cin >> from >> to >> cost;
        v[from].push_back({-cost, to});
    }
    int start, end;
    cin >> start >> end;
    for(int i = 1; i <= 1000; i++){
        dist[1001] = 210000000;
    }
    for(int i= 0; i < v[start].size(); i++){
        pq.push(v[start][i]);
    }
    check[start] = true;
    for(int i = 0; i < n-1; i++){
        




    }

}
