#include <iostream>
#include <string>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    if(a[2] > b[2])
        goto A;
    else if (a[2] < b[2])
        goto B;
    else{
        if(a[1] > b[1])
            goto A;
        else if (a[1] < b[1])
            goto B;
        else{
            if(a[0] > b[0])
                goto A;
            else
                goto B;
        }
    }
A:  cout << a[2] << a[1] << a[0] << '\n';
    return 0;
B:  cout << b[2] << b[1] << b[0] << '\n';
    return 0;
}
