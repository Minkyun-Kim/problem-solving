#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool check[1001];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >>n >>m;
        vector<int> v[n+1];
        queue<int> q;
        fill(check, check+n+1, 0);
        for(int i = 0; i < m; i++){
            int from, to;
            cin >> from >> to;
            v[from].push_back(to);
            v[to].push_back(from);
        }
        
        for(int i = 0; i < v[1].size(); i++){
            q.push(v[1][i]);
        }
        
        int ans = 0;
        check[1] = true;
        while(!q.empty()){
            int to = q.front();
            q.pop();
            if(check[to] == true)
                continue;
            check[to] = true;
            ans++;
            for(auto &node : v[to]){
                if(check[node] == false){
                    q.push(node);
                }
            }

        }
        cout << ans << '\n';

    }
    return 0;
}
