#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
//MST using kruskal
int parent[101];
vector<pair<double, double> > v(101);

struct Edge{
    int from;
    int to;
    double cost;
    bool operator<(const Edge e)const{
        return cost > e.cost;
    }
};

int find(int node){
    if(node == parent[node])
        return node;
    else
        return parent[node] = find(parent[node]);
}

void merge(int from, int to){
    int x = find(from);
    int y = find(to);
    parent[from] = to;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> v[i].first >> v[i].second;//각 별의 좌표 저장
    }
    priority_queue<Edge> pq;
    //별들끼리의 거리 저장. 크루스칼을 사용하므로 [N][N] 배열의 절반만 사용
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if( i == j )
                continue;
            double x = pow(v[i].first - v[j].first, 2);
            double y = pow(v[i].second - v[j].second, 2);
            pq.push({i, j, sqrt(x+y)});//모든 간선을 우선순위 큐에 저장
        }
    }
    double ans = 0;
    for(int i = 0; i < n-1; i++){
        int from = pq.top().from;
        int to = pq.top().to;
        double cost = pq.top().cost;// 연결할 간선 추출
        ans += cost;//별 사이의 거리 더하기
        merge(parent[from], parent[to]);//두 별 연결
        while(!pq.empty()){
            if( find(pq.top().from) == find(pq.top().to) )//다음 추출할 간선이 사이클을 구성하면 버림
                pq.pop();
            else
                break;
        }

    }
    printf("%.2f\n", ans);
    return 0;
    

}
