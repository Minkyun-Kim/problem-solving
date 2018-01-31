#include <cstdio>
#include <queue>
using namespace std;
int earth[52][52];
int check[52][52];
int dx[] = {-1, 0, 1, 0,};
int dy[] = {0, 1, 0,  -1,};
void bfs(int i,int j){
    queue<pair<int, int> > q;
    q.push({i, j});
    check[i][j] = 1;
    while(!q.empty()){
        pair<int, int> pr = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = pr.first + dx[i];
            int ny = pr.second + dy[i];
            if(check[nx][ny] == 0 && earth[nx][ny] == 1){
                q.push({nx, ny});
                if(check[nx][ny] == 0 || check[nx][ny] > check[pr.first][pr.second]+1){
                    check[nx][ny] = check[pr.first][pr.second] + 1;               
                }
            }
        }
    }
}


int main(){
    int n, m;
    scanf("%d %d\n", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%1d", &earth[i][j]);
        }
    }
    bfs(1, 1);
    printf("%d\n", check[n][m]);
}
