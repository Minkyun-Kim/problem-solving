#include <bits/stdc++.h>
using namespace std;

int main(){
    int temp;
    int min = 0, man = 0;
    for(int i = 0; i < 8; i++){
        cin >> temp;
        if(i < 4)
            min += temp;
        else
            man += temp;
    }
    if(min >= man)
        cout << min << '\n';
    else
        cout << man << '\n';
    return 0;
}
