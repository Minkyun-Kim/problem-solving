#include <bits/stdc++.h>
using namespace std;

long long arr[68];
long long koong(int);
int main(){
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        cout << koong(num) << '\n';
    }
    return 0;
}

long long koong(int num){
    if(arr[num] != 0) 
        return arr[num];
    arr[num] = koong(num-1) + koong(num-2) + koong(num-3) + koong(num-4);
    return arr[num];
}
