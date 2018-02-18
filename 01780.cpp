#include <iostream>
#include <vector>
using namespace std;
int v[2187][2187];
int cnt[3];

bool check(int x, int y, int n){
    for(int i = x;  i < x+n; i++){
        for(int j = y; j < y+n; j++){
            if(v[i][j] != v[x][y])
                return false;
        }
    }
    return true;
}

void divide(int x, int y, int n){
    if(check(x, y, n)){
        cnt[v[x][y]+1]++;
        return;
    }
    int m = n / 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            divide(x+i*m, y+j*m, m);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
    divide(0, 0, n);
    cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << '\n';
    return 0;
}
