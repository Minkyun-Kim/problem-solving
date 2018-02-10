#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> d(n);
    for(int i =  0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++){
        d[i] = 1;
        /*
            d[i] 는 a[i]가 마지막일 때 그보다 작은 수의 d[j]+1이다. 말로 설명하려니까 잘
            안되네...
           */
        for(int j = 0; j < i; j++){
            if(a[j] < a[i] && d[j] + 1 > d[i])
                d[i] = d[j] + 1;
        }
    }
    cout<< *max_element(d.begin(), d.end()) << '\n';
    return 0;
}
