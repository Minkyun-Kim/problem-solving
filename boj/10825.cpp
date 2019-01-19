#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n;
    vector<tuple<int, int, int, string>> v;
    string s;
    int i, j, k;
    cin >> n;
    while(n--){
        cin >> s >> i >> j >> k;
        v.push_back(make_tuple(i, j, k, s));
    }
   /* sort(v.begin(), v.end(), [](tuple<int, int, int, string> t1, tuple<int, int, int, string> t2){
            return make_tuple(-get<0>(t1), get<1>(t1), -get<2>(t1), get<3>(t1))
                    < make_tuple(-get<0>(t2), get<1>(t2), -get<2>(t2), get<3>(t2));});
    */
    sort(v.begin(), v.end(), [](tuple<int, int, int, string> t1, tuple<int, int, int, string> t2){
        if(get<0>(t1) > get<0>(t2))
            return true;
        else if(get<0>(t1) == get<0>(t2)){
                if(get<1>(t1) < get<1>(t2))
                    return true;
                else if(get <1>(t1) == get<1>(t2)){
                    if(get<2>(t1) > get<2>(t2))
                        return true;
                    else if(get<2>(t1) == get<2>(t2))
                        return get<3>(t1) < get<3>(t2);
                }
        }
            return false;
        });
        
    for(auto it = v.begin(); it!=v.end(); it++){
        cout << get<3>(*it)<< '\n';
    }
    return 0;
}
