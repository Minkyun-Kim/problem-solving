#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    int left = 1000 - n;
    if(left >= 500){
        left %= 500;
        ans++;
    }
    if(left >= 100){
        ans += left/100;
        left %= 100;
    }
    if(left >= 50){
        ans += left/50;
        left %= 50;
    }
    if(left >= 10){
        ans += left/10;
        left %= 10;
    }
    if(left >= 5){
        ans += left/5;
        left %= 5;
    }
    ans += left;
    cout << ans << '\n';
    return 0;
}
