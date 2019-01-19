#include <bits/stdc++.h>
using namespace std;

bool arr[4];

int main(){
    int n;
    cin >> n;
    arr[1] = true;
    while(n--){
        int from, to;
        cin >> from >> to;
        if(arr[from] == true){
            arr[from] = false;
            arr[to] = true;
        }
        else if(arr[to] == true){
            arr[to] = false;
            arr[from] = true;
        }
    }
    if(arr[1] == true)
        cout << 1 << '\n';
    else if (arr[2] == true)
        cout << 2 << '\n';
    else 
        cout << 3 << '\n';
    return 0;
}
