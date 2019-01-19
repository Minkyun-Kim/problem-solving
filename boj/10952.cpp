#include <iostream>
using namespace std;

int main(){
    int i, j;
    while(1){
        cin >> i >> j;
        if(i == 0 && j == 0)
            break;
        cout<< i + j << '\n';
    }
    return 0;
}
