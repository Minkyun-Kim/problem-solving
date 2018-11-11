#include <bits/stdc++.h>
using namespace std;

int arr[101][101];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < 2; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= m; k++){
                int temp;
                cin >> temp;
                arr[j][k] += temp;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
