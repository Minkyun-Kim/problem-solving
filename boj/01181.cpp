#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> v;
    string s;
    while(n--){
        cin >> s;
        if(v.end() == find(v.begin(), v.end(), s))
            v.push_back(s);
    }
    sort(v.begin(), v.end(), [](string u, string v){
            if (u.size() < v.size())
                return true;
            else if (u.size() == v.size())
                return u < v;
            else
                return false;
            });
    auto it = v.begin();
    while(it != v.end()){
        cout << *it << '\n';
        it++;
    }
    return 0;
}
