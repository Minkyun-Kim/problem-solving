#include <iostream>
using namespace std;
int a[1001];
bool check[1001];

bool dfs(int i){
    if(dfs(a[i]) == true)
        return;
    check[i] = true;
    dfs(a[i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            check[i] = false;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(check[i] == false){
                dfs(i);
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
