#include <iostream>
using namespace std;
int arr[1001][10];
int mod = 10007;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i  <= 9; i++)
        arr[1][i] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= 9; j++){
            arr[i][j] = 0;
            for(int k = 0; k <= j; k++){
                arr[i][j] += arr[i-1][k];
            }
            arr[i][j] %= mod;
        }
    }
    int sum = 0;
    for(int i = 0; i <= 9; i++){
        sum = (sum + arr[n][i]) % mod;
    }
    cout << sum << '\n';
    return 0;
}
