#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int a[27][27];
int check[27][27];

int dfs(int i, int j){
    stack<pair<int, int> > st;
    st.push(make_pair(i, j));
    int cnt = 1;
    check[i][j] = 1;
    while(!st.empty()){
        pair<int, int> pr = st.top();
        if(!check[pr.first-1][pr.second] && a[pr.first-1][pr.second]){
            cnt++;
            st.push({pr.first-1, pr.second});
            check[pr.first-1][pr.second] = 1;
        }
        else if(!check[pr.first][pr.second+1] && a[pr.first][pr.second+1]){
            cnt++;
            st.push({pr.first, pr.second+1});
            check[pr.first][pr.second+1] = 1;            
        }
        else if(!check[pr.first+1][pr.second] && a[pr.first+1][pr.second]){
            cnt++;
            st.push({pr.first+1, pr.second});
            check[pr.first+1][pr.second] = 1;
        }
        else if(!check[pr.first][pr.second-1] && a[pr.first][pr.second-1]){
            cnt++;
            st.push({pr.first, pr.second-1});
            check[pr.first][pr.second-1] = 1;
        }
        else{
            st.pop();    
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            a[i][j+1] = s[j] -'0';
        }
    }
    vector<int> v;
    int ans=0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] && !check[i][j]){
                v.push_back(dfs(i, j));
                ans++;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << ans << '\n';
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << '\n';
    }
    return 0;
}
