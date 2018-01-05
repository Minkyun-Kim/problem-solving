#include <iostream>
using namespace std;
bool a[1000001];

int main(){
    int n, m;
    cin >> n >> m;
    a[1] = true;
    for(int i = 2; i*i <= m; i++){
        for(int j = i; i*j <= m; j++){
            a[i*j] = 1;               
        }
    }
    for(int i = n; i <= m; i++)
        if(a[i] == 0)
            cout << i << '\n';
    return 0;

}
