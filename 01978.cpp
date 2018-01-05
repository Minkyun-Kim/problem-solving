#include <iostream>
using namespace std;

bool prime(int n){
    if(n == 1)
        return false;
    else{
        for(int i = 2; i*i <= n; i++){
            if(n % i == 0)
                return false;
        }
    }
    return true;
}
    
int main(){
    int n, cnt = 0, m;
    cin >> n;
    while(n--){
        cin >> m;
        if(prime(m))
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
