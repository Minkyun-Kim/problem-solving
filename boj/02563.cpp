#include <iostream>
using namespace std;
int arr[100][100];

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int left, right;
        cin >> left >> right;
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                if(arr[left+j][right+k] == 0){
                    cnt++;
                    arr[left+j][right+k] = 1;
                }
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
