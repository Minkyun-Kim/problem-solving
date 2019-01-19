#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, w, h;
    cin >> n >> w >> h;
    int diag = sqrt(w*w+h*h);
    for(int i = 0; i < n; i++){
        int match;
        cin >> match;
        if(match <= diag){
            cout << "DA" << '\n';
        }
        else
            cout <<"NE" << '\n';
    }
    return 0;
}
