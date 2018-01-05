#include <iostream>
using namespace std;
int d[100001];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        d[i] = i;
        for(int j = 1; j*j <= i; j++)
            if(d[i] > d[i-j*j]+1)
                d[i] = d[i-j*j]+1;
    }
    cout << d[n] << '\n';
    return 0;
}
