#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    set<string> everListened, everLS;
    int n, m;
    cin >> n >> m;
    string name;
    while(n--){
       cin >> name;
       everListened.insert(name);
    }
    while(m--){
        cin >> name;
        if(everListened.count(name))
            everLS.insert(name);
    }
    set<string>::iterator it = everLS.begin();
   cout << everLS.size() << "\n";
    while(it != everLS.end()){
        cout<<*it<<"\n";
        it++;
    }
}
