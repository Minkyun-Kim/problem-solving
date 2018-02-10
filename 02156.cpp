#include <iostream>
using namespace std;

long long wine[10001];
long long arr[10001][3];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> wine[i];
    arr[0][0] = arr[0][1] = arr[0][2] = 0;
    /*
       0은 연속해서 마시지 않은 경우
       1은 한번 연속해서 마신 경우
       2는 두번 연속해서 마신경우

       0은 그 전에 연속해서 마시든 안마시든 가장 큰 값을 가져오면 된다.
       1은 한번 연속해서 마셨기 때문에  그 전에 아무것도 안먹고 이번에 마셔야 한번연속마신게 된다.
       2는 두번 연속해서 마셨기 때문에 그 전에 한번 마신 경우에 지금 마셔야 두번연속이 된다.
       */
    for(int i = 1; i<= n; i++){
        arr[i][0] = max(arr[i-1][0], max(arr[i-1][1], arr[i-1][2]));
        arr[i][1] = arr[i-1][0] + wine[i];
        arr[i][2] = arr[i-1][1] + wine[i];
    }
    cout<< max(arr[n][0], max(arr[n][1], arr[n][2])) << '\n';
    return 0;
}
