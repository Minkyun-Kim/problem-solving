#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, max = 0;
    cin >> n;
    vector<int> v;
    while(n--){
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(), v.end());
    do{
        int sum = 0;
        for(auto it = v.begin(); it + 1 !=v.end(); it++){
            sum += abs(*it - *(it + 1));
        }
        if(sum > max)
            max = sum;

        
    }while(next_permutation(v.begin(), v.end()));
    cout<< max << '\n';
    return 0;
}
