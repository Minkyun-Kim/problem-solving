#include <iostream>
#include <queue>
using namespace std;
int land[100][100];
int group[100][100];
int dist[100][100];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> land[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(land[i][j] == 1 && group[i][j] == 0){
                group[i][j] = ++cnt;
                queue<pair<int, int> > q;
                q.push({i, j});
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < n){
                            if(land[nx][ny] == 1 && group[nx][ny] == 0){
                                group[nx][ny] = cnt;
                                q.push({nx, ny});
                            }
                        }
                    }
            
                }
            }
        }
    }

    queue<pair<int, int> > q;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dist[i][j] = -1;
            if(land[i][j] == 1){
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(0 <= nx && nx < n && 0 <= ny && ny < n){
                if(dist[nx][ny] == -1){
                    dist[nx][ny] = dist[x][y] + 1;
                    group[nx][ny] = group[x][y];
                    q.push({nx, ny});
                }
            }
        }
    }
    
    int ans = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(0 <= x && x < n && 0 <= y && y < n){
                    if(group[i][j] != group[x][y]){
                        if(ans == -1 || ans > dist[i][j] + dist[x][y]){
                            ans = dist[i][j] + dist[x][y];
                        }
                    }
                }
            }
        }
    }
    cout << ans <<'\n';
    return 0;
}
