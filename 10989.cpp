#include <cstdio>
#include <algorithm>
using namespace std;
int a[100001];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i< n; i++){
        int m;
        scanf("%d", &m);
        a[m]++;
    }
    for(int i = 0; i < 10000; i++){
        if(a[i] > 0){
            while(a[i]--)
                printf("%d\n", i);
        }
    }
    return 0;
}
