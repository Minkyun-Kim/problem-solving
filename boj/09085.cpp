#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        int ans = 0;
        for(int i = 0; i < num; i++){
            int temp;
            cin >> temp;
            ans += temp;
        }
        cout << ans << '\n';
    }
    return 0;
}
