#include <bits/stdc++.h>
using namespace std;

int arr[2][1001];

int main(){
    int ans[2];
    int n1, n2;
    for(int i = 0; i < 3; i++){
        cin >> n1 >> n2;
        arr[0][n1]++;
        arr[1][n2]++;
    }
    int answ1, answ2;
    for(int i = 0; i <= 1000; i++){
        if(arr[0][i] == 1){
            cout <<i << ' ';
            break;
        }
    }
    for(int i = 0; i <=1000; i++){
        if(arr[1][i] == 1){
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
