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
            d[i] = max(d[i], d[i-j]+p[j]);//[i-j] + [j] = 총 i개가 됨.i개를 살 때 가격은                                   
        }                               //j개의 패키지를 사고, 남은갯수는 d[]를통해
    }                                   //최대가격을 뽑아낼수 있다.
    cout << d[n] << '\n';
    return 0;
}
