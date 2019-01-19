#include <stack>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
    stack<char> s1, s2;
    int n;
    char c;
    while(c = getchar()){
        if(c == '\n')
            break;
        s1.push(c);
    }
    scanf("%d ", &n);
    while(n--){
        char cmd;
        scanf("%c ", &cmd);
        if(cmd == 'L'){
            if(s1.empty()){}
            else{
                s2.push(s1.top());
                s1.pop();
            }
        }
        else if(cmd == 'D'){
            if(s2.empty()){}
            else{
                s1.push(s2.top());
                s2.pop();
            }
        }
        else if(cmd == 'B')
            s1.pop();
        else{
            char ch;
            scanf("%c\n", &ch);
            s1.push(ch);
        }
    }
    
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    while(!s2.empty()){
        printf("%c", s2.top());
        s2.pop();
    }


    return 0;
}
