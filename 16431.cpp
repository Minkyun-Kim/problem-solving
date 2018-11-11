#include <bits/stdc++.h>
using namespace std;

int main(){
    int br, bc, dr, dc, jr, jc;
    cin >> br >> bc >>dr >>dc >> jr >> jc;
    int b_ans = 0, d_ans = 0;
    d_ans = abs(jr-dr) + abs(jc-dc);
    if(abs(jr-br) < abs(jc-dc)){
        b_ans += abs(jr-br);
        b_ans += abs(jc-br) - abs(jr-br);
    }
    else if(abs(jr-br) > abs(jc-dc)){
        b_ans += abs(jc-dc);
        b_ans += abs(jc-dc) - abs(jr-br);
    }
    else{
        b_ans = abs(jr-br);
    }
    if(b_ans < d_ans)
        cout << "bessie" << '\n';
    else if(b_ans > d_ans)
        cout << "daisy" << '\n';
    else
        cout << "tie" << '\n';
    return 0;
}
