#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> pq;
    int n, m;
    cin >> n;
    while(n--){
        cin >> m;
        if( m > 0)
            pq.push(-m);
        else
            if(pq.empty())
                cout<< 0 <<'\n';
            else{
                cout << -pq.top()<<'\n';
                pq.pop();
            }
    }
    return 0;
}
