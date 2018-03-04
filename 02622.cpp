#include <iostream>
using namespace std;

int main(){
    int n, cnt = 0;
    cin >> n;
    for(int a = 1; a < n-1; a++){
        for(int b = a; b < n; b++){
            int c = n - (a + b);
            if( c < b) 
                break;
            if( b + a > c) 
                cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}
