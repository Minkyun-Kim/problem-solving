#include <iostream>
#include <queue>
using namespace std;

int depth[100001];
int check[100001];
vector<vector<pair<int, int> > > v(100001);
queue<pair<int, int> > q;

void bfs(int start){
    q.push({start, 0});
    check[start] = 1;
    while(!q.empty()){
        int to = q.front().first;
        int cost = q.front().second;
        q.pop();
        for(pair<int, int> pr : v[to]){    
            if(check[pr.first] == 0){
                q.push({pr.first, pr.second});
                check[pr.first] = 1;
                depth[pr.first] = depth[to] + pr.second;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({to, cost});
        v[to].push_back({from, cost});
    }

    bfs(1);
    int far = 0, pos = 0;;
    for(int i = 1; i <= n; i++){
        if(far < depth[i]){
            far = depth[i];
            pos = i;
        }
        depth[i] = 0;
        check[i] = 0;
    }
    bfs(pos);
    far = 0;
    for(int i = 1; i <= n; i++){
        if(far < depth[i])
            far = depth[i];
    }
    cout << far << '\n';
    return 0;
}
