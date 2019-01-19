#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int i;
    for( i = 1; i <= n; i++){
        if(n%i == 0){
            k--;
        }
        if(k == 0)
            break;
    } 
    if(k != 0)
        cout << 0 << '\n';
    else
        cout << i << '\n';
    return 0;
}
