#include <iostream>
#include <set>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<int> s;
    while(n--){
        int el;
        cin>>el;
        s.insert(el);
    }
    auto it = s.begin();
    while(it != s.end()){
        cout<<*it<<' ';
        it++;
    }
    cout<<'\n';
    return 0;
    
}
