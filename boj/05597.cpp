#include <bits/stdc++.h>
using namespace std;

bool check[31];

int main(){
    for(int i = 0; i < 28; i++){
        int stu;
        cin >> stu;
        check[stu] = true;
    }
    for(int i = 1; i <= 30; i++){
        if(check[i] == false)
            cout << i << '\n';
    }
    return 0;
}
