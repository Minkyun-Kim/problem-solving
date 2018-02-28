#include <iostream>
using namespace std;

int main(){
    int a[9];
    bool asc = 1, des = 1;
    for(int i = 1; i <= 8; i++){
        cin >> a[i];
        if(a[i] != i)
            asc = 0;
        if(a[i] != 9-i)
            des = 0;
    }
    if(asc == 1)
        cout << "ascending";
    else if(des == 1)
        cout << "descending";
    else
        cout << "mixed";
    cout << '\n';
    return 0;
}
