#include <iostream>
using namespace std;
int a[2187][2187];
void recur(int x, int y, int n){
    if(n == 1)
        a[x][y] = 1;
    else{
        int dn = n/3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if( i == 1 && j == 1)
                    continue;
                recur(x + i*dn, y + j*dn, dn);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    recur(0, 0, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1)
                cout << "*";
            else
                cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
