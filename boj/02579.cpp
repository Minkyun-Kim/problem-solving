#include <iostream>
#include <algorithm>
using namespace std;

//ver1
int a[301];
int d[301];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i<= n; i++)
        cin >> a[i];
    d[1] = a[1];
    d[2] = a[1] + a[2];
    for(int i = 3; i <= n; i++)
        d[i] = max(d[i-2] + a[i], d[i-3] + a[i] + a[i-1]);
    cout << d[n];
    return 0;
}

/*
   ver2
int a[301];
int d[301][3];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    d[1][1] = a[1];
    for(int i = 2; i<= n; i++){
        d[i][2] = d[i-1][1] + a[i];
        d[i][1] = max(d[i-2][1], d[i-2][2] + a[i]);
    }
    cout << max(d[n][1], d[n][2]) << '\n';
    return 0;
}
*/
