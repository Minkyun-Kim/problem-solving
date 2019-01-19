#include <iostream>
using namespace std;
int check[1001];

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 2; i <= n; i++){
        for(int j = 1; i*j <= n; j++){
            if(check[i*j] == 0){
                check[i*j] = 1;
                k--;
                if(k == 0){
                    cout << i*j << '\n';
                    return 0;
                }
            }
        }
    }

}
