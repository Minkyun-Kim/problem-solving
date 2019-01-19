#include <iostream>
#include <queue>
using namespace std;
bool earth[52][52];
bool check[52][52];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
void bfs(int i,int j){
    queue<pair<int, int> > q;
    q.push({i, j});
    while(!q.empty()){
        pair<int, int> pr = q.front();
        q.pop();
        for(int i = 0; i < 8; i++){
            int nx = pr.first + dx[i];
            int ny = pr.second + dy[i];
            if(check[nx][ny] == 0 && earth[nx][ny] == 1){
                q.push({nx, ny});
                check[nx][ny] = 1;
            }
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(1){
        int w, h;
        cin >> w >> h;
        if(w == 0 && h == 0)
            break;
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                cin >> earth[i][j];
                check[i][j] = 0;
            }
        }

        int ans = 0;
        for(int i = 1; i <= h; i++){
            for (int j = 1; j <= w; j++){
                if(check[i][j] == 0 && earth[i][j] == 1){
                    bfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}
