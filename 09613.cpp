#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if (b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int main(){
    int n, m, a;
    cin >> n;
    while(n--){
        cin >> m;
        vector<int> v;
        int sum = 0;
        for( int i = 0; i < m; i++){
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end(), greater<int>());
        for(int i = 0; i <= m-2; i++){
            for(int j = i+1; j <= m-1; j++){
                sum += gcd( v[i], v[j]);
            }
        }
        cout<< sum << '\n';
    }
    return 0;
}
