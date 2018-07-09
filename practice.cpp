#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int work[10001];
vector<int> v[10001];
int d[10001];
int ind[10001];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int cnt;
        cin >> cnt;
        for(int i = 0; i < cnt; i++){
            int from;
            cin >> from;
            v[from].push_back(i);
            ind[i] += 1;
        }
    }
    queue<int> q;
    for(int i = 0; i <= n; i++){
        if(ind[i] == 0){
            q.push(i);
            d[i] = work[i];//초기 ind==0 인 작업시간을 기록
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i <= v[x].size(); i++){
            int y = v[x][i];
            ind[y] -= 1;
            if(d[y] < d[x] + work[y]){
                d[y] = d[x] + work[y];
            }
            if(ind[y] == 0){
                q.push(y);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <=n ; i++){
        if(ans < d[i] ){
            ans = d[i];
        }
    }
    cout << ans << '\n';
    return 0;
}
