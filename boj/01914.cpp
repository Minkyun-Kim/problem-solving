//n = 64부터 오버플로우가 난다.
#include <iostream>
#include <string>
using namespace std;

void hanoi(int n, int from, int to){
    if(n == 0)
        return;
    hanoi(n-1, from, 6-from-to);
    cout << from << ' ' << to << '\n';
    hanoi(n-1, 6-from-to, to);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    string s[2];
    cin >> n;
    long long move = 1;
    if(n <= 20){
        for(int i = 2; i <= n; i++){
            move = 2*move +1;
        }
        cout << move << '\n';
        hanoi(n, 1, 3);
    }

    else if(n < 64){
        for(int i = 2; i <= n; i++){
            move = 2*move +1;
        }
        cout << move << '\n';
    
    }
    else{
        for(int i = 2; 
    }


}
