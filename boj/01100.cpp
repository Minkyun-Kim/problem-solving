#include <bits/stdc++.h>
using namespace std;

char arr[8][8];

int main(){
    int cnt = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> arr[i][j];
            if(i%2==0){
                if(j%2==0){
                    if(arr[i][j] == 'F')
                        cnt++;
                }
            }
            else{
                if(j%2==1){
                    if(arr[i][j] == 'F')
                        cnt++;
                }
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
