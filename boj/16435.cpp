#include <bits/stdc++.h>
using namespace std;

int arr[1000];

int main(){
    int n, L;
    cin >> n >> L;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i = 0; i < n; i++){
        if(L >= arr[i])
            L++;
        else
            break;
    }
    cout << L << '\n';
    return 0;
}
