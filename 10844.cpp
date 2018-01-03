#include <iostream>
#include <vector>
using namespace std;
long long arr[101][10];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i<=9 ; i++)
        arr[1][i] = 1;

    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= 9; j++){
            arr[i][j] = 0;
            if( j-1 >= 0)
                arr[i][j] += arr[i-1][j-1];
            if( j+1 <= 9)
                arr[i][j] += arr[i-1][j+1];
            arr[i][j] %= 1000000000;
        }
    }
    long long sum = 0;
    for(int i = 0 ; i <= 9; i++)
        sum = (arr[n][i]+ sum) %1000000000;
    cout<< sum << '\n';
    return 0;

}
