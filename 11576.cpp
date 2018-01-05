#include <iostream>
using namespace std;

void convert(int ans, int base){
    if(ans == 0)
        return;
    convert(ans/base, base);
    cout << ans%base << ' ';
}

int main(){
    int a, b;
    cin >> a >> b;
    int m;
    cin >> m;
    int ans = 0;
    while( m-- ){
        int n;
        cin >> n;
        ans = ans * a + n;
    }
    convert(ans, b);
    cout<< '\n';
    return 0;
}
