#include <iostream>
using namespace std;

int main(){
    long long s;
    cin >> s;
    long long sum = 0;
    int i = 0;
    while( sum < s){
        sum += ++i;
    }
    if(sum == s)
        cout << i << '\n';
    else
        cout << i-1 << '\n';
    return 0;
}
