#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int num;
    string s1, s2;
    cin >> num;
    while(num--){
        vector<int> v;
        cin >> s1 >> s2;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] <= s2[i])
                v.push_back(s2[i]-s1[i]);
            else
                v.push_back(s2[i]+26-s1[i]);
        }
        cout << "Distances: ";
        for(int i = 0; i < v.size(); i++){
            cout << v[i] <<' ';
        }
        cout << '\n';
    }
    return 0;
}
