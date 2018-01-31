#include <iostream>
#include <queue>
using namespace std;
int tom[1000][1000];
int dist[1000][1000];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    int n, m;
    cin >> m >> n;
    queue<pair<int, int> > q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> tom[i][j];
            dist[i][j] = -1;
            if(tom[i][j] == 1){
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m){
                if(tom[nx][ny] == 0 && dist[nx][ny] == -1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ans < dist[i][j])
                ans = dist[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dist[i][j] == -1 && tom[i][j] == 0)
                ans = -1;
        }
    }
    cout << ans << '\n';
    return 0;
}
