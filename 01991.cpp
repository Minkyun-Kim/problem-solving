#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<char> > v(26, vector<char>(2));
    int n;
    while(n--){
        char c[3];
        cin >> c[0] >> c[1] >> c[2];
        if(c[1] != '.')
            v[c[0]-'A'][0] = c[1];
        if(c[2] != '.')
            v[c[0]-'A'][1] = c[2];
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 2; j++){
            cout << v[i][j] << '\n';
        }
    }
    return 0;
}
