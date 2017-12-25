#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

int main(){
    int n;
    int m;
    cin>>n;
    set<int> s;
    while(n--){
        int card;
        scanf("%d ", &card); 
        s.insert(card);
    }
    scanf("%d\n", &n);
    while(n--){
        int card;
        scanf("%d", &card);
        if(s.count(card))
            printf("1 ");
        else
            printf("0 ");
    }
    printf("\n");
    return 0;
}
