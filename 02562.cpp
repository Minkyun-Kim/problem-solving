#include <iostream>
using namespace std;
int a[10];

int main(){
    int pos = 1;
    for(int i = 1; i <= 9; i++){
        cin >> a[i];
        if(a[pos] < a[i])
            pos = i;
    }
    cout << a[pos] << '\n' << pos << '\n';
    return 0;
}
