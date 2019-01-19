#include <sstream>
#include <string>
#include <iostream>
using namespace std;

int main(){
    string s, line;
    while(getline(cin, line))
        s += line;    
    istringstream sin(s);

    string number;
    int sum = 0;
    
    while (getline(sin, number, ',')){
        sum += stoi(number);
    }

    cout<< sum << '\n';
    return 0;

}
