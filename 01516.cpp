#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[501];
int ind[501];
int tim[501];
int cum[501];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> tim[i];

        while(1){
            int node;
            cin >> node;
            if(node == -1)
                break;
            v[node].push_back(i);
            ind[i] += 1;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(ind[i] == 0){
            q.push(i);
            cum[i] = tim[i];
        }
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < v[x].size(); i++){
            int y = v[x][i];
            ind[y] -= 1;
            if(ind[y] == 0){
                q.push(y);
            }
            if(cum[y] < cum[x] + tim[y]){
                cum[y] = cum[x] + tim[y];
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << cum[i] << '\n'; 
    }

    return 0;


}
