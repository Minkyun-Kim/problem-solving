/*
   90프로 넘어서 틀렸습니다.... 왜일까
   */
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000001];

int divide(int left, int right){
    if(left == right)
        return a[left];
    int mid = (left + right) / 2;
    int ret = max(divide(left, mid), divide(mid+1, right));
    int low = mid;
    int high = mid+1;
    int height = min(a[mid], a[mid+1]);
    ret = max(ret, height*2);
    while(left < low || high < right){
        if(high < right && (left == low || a[low-1] < a[high+1])){
            high++;
            height = min(height, a[high]);
        }
        else{
            low--;
            height = min(height, a[low]);
        }
        ret = max(ret, height*(high - low +1));
    }
    return ret;
}


int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << divide(1, n) << '\n';
    return 0;
}
