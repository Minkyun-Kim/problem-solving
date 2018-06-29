#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[32001];
int ind[32001];
int main(){
    int n, m;
    cin >> n >> m;
    queue<int> q;
    while(m--){
        int small, tall;
        cin >> small >> tall;
        v[small].push_back(tall);
        ind[tall]++;
    }

    for(int i = 1; i <= n; i++){
        if(ind[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int x = q.front();
        q. pop();
        cout << x << " ";
        for(int i = 0; i < v[x].size(); i++){         
            int y = v[x][i];
            ind[y] -= 1;
            if(ind[y] == 0){
                q.push(y);
            }
        }
    }
    cout << '\n';
    return 0;

}


