#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;

int main(){
    string sa, sb;
    cin>> sa >> sb;
    bitset<100000> a(sa), b(sb);
    cout << (a & b) << '\n';
    cout << (a | b) << '\n';
    cout << (a ^ b) << '\n';
    cout << (~a) << '\n';
    cout << (~b) << '\n';
    return 0; 
}
