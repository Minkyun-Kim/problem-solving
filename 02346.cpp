#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    deque<pair<int, int> > dq;
    for(int i = 1; i<=n; i++){
        int num;
        scanf("%d", &num);
        dq.push_back({num, i});
    }
    while(!dq.empty()){
        pair<int, int> balloon = dq.front();
        printf("%d ", balloon.second);
        dq.pop_front();
        if(balloon.first > 0){
            balloon.first -= 1;
            while(balloon.first--){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            dq.push_front(dq.back());
            dq.pop_back();
            balloon.first = -balloon.first;
            balloon.first -= 1;
            while(balloon.first--){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    return 0;
}
