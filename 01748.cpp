#include <iostream>
using namespace std;
long long a[91];

int main(){
    int n;
    cin >> n;
    a[1] = 1;
    for(int i = 2; i <= n; i++){
        a[i] = a[i-1] + a[i-2];
    }
    cout << a[n] << '\n';
    return 0;
}
