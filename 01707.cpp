#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > v;
vector<int> check;
vector<int> color;

bool bigraph(int node){
    queue<int> q;
    q.push(node);
    color[node] = 1;
    check[node] = 1;
    while(!q.empty()){
        node = q.front();
        q.pop();
        for(int i = 0; i < v[node].size(); i++){
            int next = v[node][i];
            if(check[next] == 0){
                q.push(next);
                check[next] = 1;
                if(color[node] == 1)
                    color[next] = 2;
                else
                    color[next] = 1;
            } 
            else if(color[node] == color[next])
                if(node != next)
                    return false;
        }
    }
    return true;
}

int main(){
    int k, n, e;
    cin >> k;
    while(k--){
        cin >> n >> e;
        v.resize(n+1);
        check.resize(n+1);
        color.resize(n+1);
        for(int i = 0; i < e; i++){
            int from, to;
            cin >> from >> to;
            v[from].push_back(to);
            v[to].push_back(from);
        }
        bool c = true;
        for(int i = 1; i <= n; i++){
            if(!check[i] && !bigraph(i)){
                c = false;
                break;
            }
        }
        if(c == true)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
        v.resize(0);
        check.resize(0);
        color.resize(0);
    }
    return 0;
}
