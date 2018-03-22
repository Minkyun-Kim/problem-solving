#include <iostream>
using namespace std;

int main(){
    int n, a, cnt = 0;
    cin >> n;
    for(int i = 0; i < 5; i++){
        cin >> a;
        if(a == n)
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
