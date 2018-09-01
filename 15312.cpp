#include <iostream>
#include <string>
#include <vector>
using namespace std;
int alp[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int main(){
    string name1;
    string name2;
    cin >> name1 >> name2;
    int len = name1.size() * 2;
    vector<int> v(len);
    for(int i = 0; i < len/2; i++){
        v[i*2] = alp[name1[i] - 65];
        v[i*2+1] = alp[name2[i] - 65];
    }
    for(int i = 0; i < len -2; i++){
        for(int j = 0; j < len-1; j++){
            v[j] = v[j] + v[j+1];
            if(v[j] >= 10)
                v[j] -= 10;
        }
    }
    cout << v[0] << v[1] << '\n';
    return 0;
    
}
