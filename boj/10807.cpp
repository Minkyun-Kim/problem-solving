#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    while(n--){
        int num;
        cin >> num;
        v.push_back(num);
    }
    cin >> n;
    cout << count(v.begin(), v.end(), n) << '\n';
    return 0;
    
}
