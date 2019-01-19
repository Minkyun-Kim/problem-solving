#include <iostream>
#include <string>
#include <vector>
using namespace std;

int arr[26];

int main(){
    string s;
    while(cin >> s){
        for(int i = 0; i < s.size(); i++){
            arr[s[i]-'a']++;
        }
    }
    int max = 0;
    for(int i = 0 ; i < 26; i++){
        if(arr[max] < arr[i]){
            max = i;
        }
    }
    cout << (char)(max+'a') << '\n';
    return 0;
}
