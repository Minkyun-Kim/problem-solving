#include <iostream>
#include <string>
using namespace std;

int main(){
    int a, b, c;
    string sum;
    cin >> a >> b >> c;
    sum = to_string(a * b * c);
    int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i = 0; i < sum.size(); i++){
        arr[sum[i]-'0']++;
    }
    for(int i = 0; i < 10; i++){
        cout<< arr[i]<<'\n';
    }
}
