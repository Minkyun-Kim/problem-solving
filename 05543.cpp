#include <iostream>
using namespace std;

int main(){
    int burger=10000, drink=10000;
    for(int i = 0; i < 3; i++){
        int temp;
        cin >> temp;
        if(temp <burger)
            burger = temp;
    }
    for(int i = 0; i < 2; i++){
        int temp;
        cin >> temp;
        if(temp < drink)
            drink = temp;
    }
    cout << burger + drink - 50 << '\n';
    return 0;
}
