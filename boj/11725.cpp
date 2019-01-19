#include <iostream>
#include <queue>
using namespace std;

vector<vector<int> > v(100001);
int parent[100001];
int check[100001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    parent[1] = 0;
    check[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int y : v[x]){
            if(check[y] == 0){
                q.push(y);
                parent[y] = x;
                check[y] = 1;
            }
        }
    }
    
    for(int i = 2; i <= n; i++)
        cout << parent[i] << '\n';

    return 0;
    
}
