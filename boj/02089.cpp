#include <iostream>
using namespace std;

void div(int n){
    if(n == 0)
        return;
    if( n%2 == 0){
        div(-(n/2));
        cout << 0 ;
    }
    else{
        if(n > 0)
            div(-(n/2));
        else
            div((-n+1)/2);
        cout <<1;
    }
}
int main(){
    int n;
    cin >> n;
    if(n == 0)
        cout << 0 << '\n';
    else
        div(n);
    cout << '\n';
    return 0;
}
