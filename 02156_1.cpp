#include <iostream>
using namespace std;

long long wine[10001];
long long arr[10001][2];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> wine[i];
    arr[1][0] = 0;
    arr[1][1] = wine[1];
    arr[2][0] = arr[1][1];
    arr[2][1] = wine[1] + wine[2];
    /*
       0 이번에 안마시는경우
       저번에 마셨거나 안마셨거나 큰 값을 가져온다
       1 이번에 마시는경우
       두번째 전에 안마시고 직전과 이번 와인값을 더한것과,
       직전에 안마시고 이번에 마신값을 더한것중 큰 수를 가져간다.

     */
    for(int i = 3; i<= n; i++){
        arr[i][0] = max(arr[i-1][0], arr[i-1][1]);
        arr[i][1] = max(arr[i-2][0] + wine[i-1] + wine[i], arr[i-1][0] + wine[i]);
    }
    cout<< max(arr[n][0],arr[n][1]) << '\n';
    return 0;
}
