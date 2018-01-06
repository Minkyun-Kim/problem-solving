#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int* a = new int[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    cout << a[k-1] << '\n';
    return 0;

}
