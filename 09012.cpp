#include <iostream>
#include <string>
#include <stack>
using namespace std;

int func(){
    stack<char> s;
    string c;
    cin >> c;
    for(int i=0; i<c.size(); i++){
        if(c[i] == '(')
            s.push(c[i]);
        else{
            if(s.empty()){
                return 0;
            }
            else
                s.pop();
        }
    }
    if(s.empty())
        return 1;
    else
        return 0;
}

int main(){
    int n;
    cin >> n;
    while (n--){
        int a = func();
        if(a==1)
            cout<<"YES"<< '\n';
        else
            cout<<"NO"<< '\n';
    }
    return 0;
}
