#include <cstdio>
int main(){
    int n, a, sum = 0;
    scanf("%d\n", &n);
    while(scanf("%1d\n", &a) && n--){
        sum += a;
    }
    printf("%d", sum);
}
