#include <string>
#include <iostream>
using namespace std;

int main(){
    string s1, s2;
    long long sum = 0;
    cin >> s1 >> s2 ;
    sum = stoll(s1 + s2);
    cin >> s1 >> s2 ;
    sum += stoll(s1 + s2);
    cout<< sum << '\n';
    return 0;
}
