#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    int num = 0;
    while(getline(cin, s, ','))
        num++;
    cout << num << '\n';
    return 0;
}
