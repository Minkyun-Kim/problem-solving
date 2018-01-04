#include <iostream>
#include <string>
using namespace std;

int main(){
    string s2, s8;
    cin >> s2;
    int front = s2.size() % 3;
    if(front == 2)
        s8.push_back((s2[0]-48)* 2 + (s2[1] - 48) + 48);
    else if(front == 1)
        s8.push_back(s2[0]);
    while(front < s2.size()-1)
        s8.push_back((s2[front++]-48) * 4 + (s2[front++]-48) * 2
            + (s2[front++]-48) + 48);
    cout<< s8 << '\n';
    return 0;
}
