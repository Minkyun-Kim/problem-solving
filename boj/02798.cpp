#include <bits/stdc++.h>
using namespace std;

int arr[100];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int max = 0;
    int sum;
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                sum = arr[i] + arr[j] + arr[k];
                if(sum <= m && max < sum)
                    max = sum;
            }
        }
    }
    cout << max << '\n';
    return 0;
}
