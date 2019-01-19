#include <iostream>
using namespace std;
int cnt;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    int cnt;
    cin >> n;
    if(n < 100){
        cout << n << '\n';
    }
    else{
        cnt = 99;
        for(int i = 100; i <= n; i++){
            int a = i/100;
            int b = (i%100)/10;
            int c = i%10;
            if( a-b == b-c)
                cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}
