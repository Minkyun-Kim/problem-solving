#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m, p;
    cin >> n >> m;
    p = n;
    int* arr = new int[n+1];
    while(n--) 
        arr[n+1] = n+1;
    int i, j, k;
    while(m--){
        cin >> i >> j >> k;
        rotate(arr+i, arr +k, arr+j+1);
    }
    for(int i = 1; i <= p; i++){
        cout << arr[i] << ' ';
    }
    cout<<'\n';
    return 0;
}
