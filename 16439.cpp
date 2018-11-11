#include <bits/stdc++.h>
using namespace std;

int arr[30][30];

int main(){
    int a, b;
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            cin >> arr[i][j];
        }
    }
    int sum = 0;
    for(int i = 0; i < b-2; i++){
        for(int j = i+1; j < b-1; j++){
            for(int k = j+1; k < b; k++){
                int temp = 0;
                for(int p = 0; p < a; p++){
                    temp += max(arr[p][i], max(arr[p][j], arr[p][k]));
                }
                if(sum < temp)
                    sum = temp;
            }
        }
    }
    cout << sum << '\n';
    return 0;
}
