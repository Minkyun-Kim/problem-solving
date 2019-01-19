#include <bits/stdc++.h>
using namespace std;

int main(){
    for(int i = 1000; i <= 9999; i++){
        int n10 = 0, n12 = 0, n16 = 0;
        for(int j = i; j > 0; j/= 10){
            n10 +=j%10;
        }
        for(int j = i; j > 0; j/= 12){
            n12 +=j%12;
        }
        for(int j = i; j > 0; j/= 16){
            n16 +=j%16;
        }
        if(n10 == n12 && n12 == n16)
            cout << i << '\n';
    }
    return 0;
}
