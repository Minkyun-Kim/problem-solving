#include <iostream>
using namespace std;

long long arr[1000001][3];
long long d[3][100001];

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= 2; i++){
            for(int j = 1; j <= n; j++){
                cin >>  d[i][j];
            }
        }
        arr[0][0] = arr[0][1] = arr[0][2] = 0;
        for(int i = 1; i <= n; i++){
            arr[i][0] = max(max(arr[i-1][0], arr[i-1][1]), arr[i-1][2]);
            arr[i][1] = max(arr[i-1][0], arr[i-1][2]) + d[1][i];
            arr[i][2] = max(arr[i-1][0], arr[i-1][1]) + d[2][i];
        }
        long long ans = 0;
        for(int i = 1; i<=n; i++)
            ans = max(max(arr[n][0], arr[n][1]), max(ans, arr[n][2]));
        cout<< ans << '\n';
    }
   
    return 0;
}
