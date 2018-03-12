nclude <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
bool check[101][101];

int main(){
        ios_base::sync_with_stdio(false); cin.tie(0);
            int n, m, k;
                cin >> n >> m >> k;
                    for(int i = 0; i < k; i++){
                                int a, b, c, d;
                                        cin >> a >> b >> c >> d;
                                                for(int i = a; i < c; i++){
                                                                for(int j = b; j < d; j++){
                                                                                    check[i][j] = 1;
                                                                                                }
                                                                        }
                                                    }
                        vector<int> ans;
                            queue<pair<int, int> > q;
                                for(int i = 0; i < n; i++){
                                            for(int j = 0; j < m; j++){
                                                            if(check[i][j])
                                                                                continue;
                                                                        int cnt = 0;
                                                                                    check[i][j] = 1;
                                                                                                q.push({i, j});
                                                                                                            while(!q.empty()){
                                                                                                                                pair<int, int> pr = q.front();
                                                                                                                                                q.pop();
                                                                                                                                                                cnt++;
                                                                                                                                                                                for(int i = 0; i < 4; i++){
                                                                                                                                                                                                        int nx = pr.first + dx[i], ny = pr.second + dy[i];
                                                                                                                                                                                                                            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                                                                                                                                                                                                                                                        continue;
                                                                                                                                                                                                                                                if(!check[nx][ny]){
                                                                                                                                                                                                                                                                            check[nx][ny] = 1;
                                                                                                                                                                                                                                                                                                    q.push({nx, ny});
                                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                            }
                                                                                                                        ans.push_back(cnt);
                                                                                                                                }
                                                }
                                    sort(ans.begin(), ans.end());
                                        cout << ans.size() << '\n';
                                            for(int i = 0; i < ans.size(); i++){
                                                        cout << ans[i] << ' ';
                                                            }
                                                cout << '\n';
                                                    return 0;
}
