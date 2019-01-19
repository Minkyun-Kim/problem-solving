/*
   string에 넣은건 항상 캐릭터 형으로 숫자를 넣어도 아스키값이 된다
   */
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    deque<int> dq;
    int carry = 0;
    int i = s1.size()-1;
    int j = s2.size()-1;
    while(i >= 0 && j >= 0){
        int temp = s1[i--] - 48 + s2[j--] - 48+ carry;
        if(temp >= 10){
            dq.push_front(temp-10);
            carry = 1;
        }
        else{
            dq.push_front(temp);
            carry = 0;
        }
    }
    if(i >= 0){
        while(i >= 0){
            int temp = s1[i--] -48 + carry;
            if(temp >= 10){
                dq.push_front(temp-10);
                carry = 1;
            }
            else{
                dq.push_front(temp);
                carry = 0;
            }
        }
    }
    else if(j >= 0){
        while( j >= 0){
            int temp = s2[j--] -48 + carry;
            if(temp >= 10){
                dq.push_front(temp-10);
                carry = 1;
            }
            else{
                dq.push_front(temp);
                carry = 0;
            }
        }
    }
    if(carry == 1)
        dq.push_front(1);
    while(!dq.empty()){
        cout << dq.front();
        dq.pop_front();
    }
    cout << '\n';
    return 0;
}
