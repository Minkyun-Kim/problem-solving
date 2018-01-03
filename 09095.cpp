#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int arr[11];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        for(int i = 3; i<= m; i++){
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        }
        cout<< arr[m] << '\n';
    }
    return 0;
}
