#include <iostream>
using namespace std;
int main(){
    int n, cnt = 0;
    cin >> n;
    while( n != 0){
        if(n % 2 == 1)
            cnt++;
        n /= 2;
    }
    cout << cnt << '\n';
    return 0;
}
