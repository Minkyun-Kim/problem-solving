#include <list>
#include <iostream>
#include <string>
using namespace std;

int main(){
    list<char> lst;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        lst.push_back(s[i]);

    list<char>::iterator it = lst.end();
    int n;
    cin>>n;
    while(n--){
        char c;
        cin >> c;
        if(c == 'L'){
            if(it != lst.begin())
                it--;
        }
        else if(c == 'D'){
            if(it != lst.end())
                it++;
        }
        else if(c == 'B'){
            if(it != lst.begin()){
                auto temp = it;
                it--;
                lst.erase(it);
                it = temp;
            }
        }
        else if(c == 'P'){
            char temp;
            cin >> temp;
            lst.insert(it, temp);
        }
    }
    
    for(char c: lst){
        cout<<c;
    }
    cout<<endl;


    return 0;
}
