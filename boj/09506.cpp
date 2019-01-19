#include <iostream>
#include <queue>
using namespace std;
bool check[100001];

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == -1)
            break;
        for(int i = 1; i <= n; i++){
            check[i] = 0;
            if(n % i == 0){
                check[i] = 1;
            }
        }
        queue<int> q;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            if(check[i] == 1 && i != n){
                q.push(i);
                sum += i;
            }
        }
        if(sum != n)
            cout << n << " is NOT perfect." << '\n';
        else{
            cout << n << " = " << q.front();
            q.pop();
            while(!q.empty()){
                cout << " + " << q.front();
                q.pop();
            }
            cout << '\n';
        }
    }
    return 0;
}
