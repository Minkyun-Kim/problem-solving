#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> d(n+1), p(n+1);
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            d[i] = max(d[i], d[i-j]+p[j]);
        }
    }
    cout << d[n] << '\n';
    return 0;
}
