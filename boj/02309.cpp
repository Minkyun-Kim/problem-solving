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
    int i, j;
    for(i = 0; i < 8; i++){
        for(j = i+1; j < 9; j++){
            if(a[i] + a[j] == sum)
                goto exit;
        }
    }
exit:
    a[i] = -1;
    a[j] = -1;
    sort(a, a+9);
    for(int k = 2; k < 9; k++){
        cout << a[k] << '\n';
    }
    return 0;
}
