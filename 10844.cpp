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
/*
   직사각형으로 배열을 그려보면 쉽게 이해할 수 있다.
   행은 n개의 자리, 열은 그때 마지막에 오는 숫자이다.
   계단수가 되려면 마지막오는 숫자보다 1작은 수가 오거나 1 큰수가 와야한다
   즉 마지막이 1이 오려면 그 전이 0 또는 2가 와야하고
   2가 오려면 그 전이 1또는 3이 와야한다.
   3이 오려면 그 전이 2또는 4가 와야한다
   즉 n자리 수에 i가 오려면 n-1자리 수에 i-1 또는 i+1이 와야한다
   그러므로 a[n][i] = a[n-1][i-1] + a[n-1][i+1] 이다.
   이때 0과 9는 i-1과 i+1을 갖지 않으므로 조건문을 통해 1~9까지만 i-1을 더해주고
   0~8까지만 i+1을 더해준다.
*/
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
