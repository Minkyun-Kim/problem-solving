#include <iostream>
#include <queue>
using namespace std;

int lab[10][10];
int cplab[10][10];
int check[10][10];
int n, m;
int xm[4] = {0, 1, 0, -1};
int ym[4] = {-1, 0, 1, 0};
queue<pair<int, int> > q;

void spread(void){
    for(int i = 0
            //이 부분에서 랩을 복사하고 원본유지하고 카피본에 스프레드 시킴.
            //체크도 초기화
            //큐도 여기서 채워야함
    while(!q.empty()){
        pair<int, int> p = q.top();
        q.pop();
        check[p.first][p.second] = true;
        for(int i = 0; i < 4; i++){
            int xNext = p.first + xm[i];
            int yNext = p.second + ym[i];
            if(lab[xNext][yNext] == 0 && check[xNext][yNext] == 0){
                q.push(pair<int, int>(xNext, yNext));
                lab[xNext][yNext] = 2;
            }
        }
    }

}

int count(void){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(lab[i][j] == 0)
                ans++;
        }
    }    
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
   
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> lab[i][j];
            if(lab[i][j] == 2)
                queue.push(pair<int, int>(i, j));
        }
    }
    for(int i = 0; i <= n+1;i++){
        lab[i][0] = 1;
        lab[i][m+1] = 1;
    }    
    for(int i = 0; i <= m+1; i++){
        lab[0][i] = 1;
        lab[n+1][i] = 1;
    }
    pair<int, int> ans1(0, 0), ans2(0, 0), ans3(0, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ans1 = pair<int, int>(i, j);
            if(lab[ans1.first][ans1.second] != 0)
                continue;
            lab[ans1.first][ans2.second] = 1;
            for(int h = 1; h <= n; h++){
                for(int b = 1; b <= m; b++){
                    ans2 = pair<int, int>(h, b);
                    if(lab[ans2.first][ans2.second] != 0)
                        continue;
                    lab[ans2.first][ans2.second] = 1;
                    for(int g = 1; g <= n; g++){
                        for(int v = 1; v <= m; v++){
                            ans3 = pair<int, int>(g, v);
                            if(lab[ans3.first][ans3.second] != 0)
                                cotinue;
                            lab[ans3.first][ans3.second] = 1;
                            spread();                        
    
                        }
                    }
                }
            }
        }
    }
    
    
    return 0;

}
