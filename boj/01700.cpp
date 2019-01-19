#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n && i < k; i++){
        cin >> v[i];
    }
    int ans = 0;
    for(int i = 0; i < k-n; i++){
        int plug;
        cin >> plug;
        vector<int>::iterator it = find(v.begin(), v.end(), plug);
        if(it == v.end()){
            int index = 0;
            for(int j = 1; j < n; j++){
                if(v[index] < v[j])
                    index = j;
            }
            v[index] = plug;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
