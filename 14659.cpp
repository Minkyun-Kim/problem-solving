#include <iostream>
using namespace std;
int achor[30001];

int main(){
    int n;
    cin >> n;
    for(int i = 1;  i <= n; i++){
        cin >> achor[i];
    }
    int ans = 0;
    for(int i = 1; i < n; i++){
        int tmp = 0;
        for(int j = i+1; j <= n; j++){
            if(achor[i] > achor[j]){
                tmp++;
            }
            if(achor[i] < achor[j])
                break;
        }
        if(ans < tmp)
            ans = tmp;
    }
    cout << ans << '\n';
    return 0;
}
