#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
            int num;
            int sum = 0;
            priority_queue<int> pq;
        for(int i = 0 ; i < 7; i++){
            cin >> num;
            if(num %2 == 0){
                sum+= num;
                pq.push(-num);
            }
        }
        cout << sum << ' ' << -pq.top() << '\n';
    }
    return 0;
}
