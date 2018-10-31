#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int> > v(5, vector<int>(4));
    vector<int> sum(5);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            cin >> v[i][j];
            sum[i] += v[i][j];
        }
    }
    int index = 0;
    int max_ele = 0;
    for(int i = 0; i < 5; i++){
        if(max_ele < sum[i]){
            max_ele = sum[i];
            index = i;
        }
    }
    cout << index+1 <<' ' << max_ele << '\n';

    return 0;
}
