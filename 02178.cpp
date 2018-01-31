#include <cstdio>
#include <queue>
using namespace std;
int earth[102][102];
int dist[102][102];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


int main(){
    int n, m;
    scanf("%d %d\n", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%1d", &earth[i][j]);
        }
    }
    
    queue<pair<int, int> > q;
    q.push({1, 1});
    dist[1][1] = 1;
    while(!q.empty()){
        pair<int, int> pr = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = pr.first + dx[i];
            int ny = pr.second + dy[i];
            if(1 <= nx && nx <= n && 1 <= ny && ny <= m){
                if(dist[nx][ny] == 0 && earth[nx][ny] == 1){
                    q.push({nx, ny});
                    dist[nx][ny] = dist[pr.first][pr.second] + 1;
                }
            }
        }
    }
    printf("%d\n", dist[n][m]);
    return 0;
}
