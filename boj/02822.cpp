#include <bits/stdc++.h>
using namespace std;

int main(){
    pair<int, int> pr[8];
    int sum = 0;
    for(int i = 0; i < 8 ; i++){
        cin >> pr[i].first;
        pr[i].second = i;
    }
    sort(pr, pr+8);
    int ans[5];
    for(int i = 0; i < 5; i++){
        ans[i] = pr[i+3].second;
        sum += pr[i+3].first;
    }
    sort(ans, ans+5);
    cout << sum << '\n';
    for(int i = 0; i < 5; i++){
        cout << pr[ans[i]] << ' ';
    }
    cout << '\n';
    return 0;
}
