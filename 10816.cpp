#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<int, int> mp;
    int n, m, card;
    scanf("%d\n", &n);
    while(n--){
        scanf("%d ", &card);
        mp[card]++;
    }
    scanf("%d\n", &m);
    while(m--){
        scanf("%d", &card);
        printf("%d ", mp[card]);
    }
    printf("\n");
    return 0;
}
