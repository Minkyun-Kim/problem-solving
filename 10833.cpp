#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    while(n--){
        int student, apple;
        cin >> student >> apple;
        ans += apple%student;
    }
    cout << ans << '\n';
    return 0;
}
