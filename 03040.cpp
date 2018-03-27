#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a[9];
    int sum = 0;
    for(int i = 0; i < 9; i++){
        cin >> a[i];
        sum += a[i];
    }
    sum -= 100;
    for(int i = 0; i < 8; i++){
        for(int j = i+1; j < 9; j++){
            if(a[i] + a[j] == sum){
                a[i] = -1;
                a[j] = -1;
                goto exit;
            }
        }
    }
exit:
    for(int k = 0; k < 9; k++){
        if(a[k] != -1)
            cout << a[k] << '\n';
    }
    return 0;
}
