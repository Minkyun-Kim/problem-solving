#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> v;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, p;
    cin >> a >> p;
    v.push_back(0);
    v.push_back(a);

    while(1){
        int last = *(v.end() -1);
        int next = 0;
        while(last != 0){
            next += pow(last %10, p);
            last = last/10;
        }
        v.push_back(next);
        for(int i = 1; i < v.size()-1; i++){ 
            if(v[i] == next){   
                cout << i-1 << '\n';
                goto END; 
            }
        }
    }
END:
    return 0;
}
