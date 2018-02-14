#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> plus;
    vector<int> minus;
    int one = 0, zero = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num < 0)
            minus.push_back(num);
        else if(num > 1)
            plus.push_back(num);
        else if(num == 1)
            one++;
        else if(num == 0)
            zero = 1;
    }
    sort(plus.begin(), plus.end(), greater<int>());
    sort(minus.begin(), minus.end());
    if(plus.size() % 2 == 1)
        plus.push_back(1);
    if(minus.size() % 2 == 1)
        minus.push_back(zero == 1? 0:1);
    int ans = one;
    for(int i = 0; i < plus.size(); i += 2)
        ans += plus[i] * plus[i+1];
    for(int i = 0; i < minus.size(); i += 2)
        ans += minus[i] * minus[i+1];

    cout << ans << '\n';
    return 0;
}
