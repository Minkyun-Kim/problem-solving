#include <cstdio>

int main(){
    int n, i, j;
    scanf("%d\n", &n);
    for(int k = 1; k <= n; k++){
        scanf("%d %d", &i, &j);
        printf("Case #%d: %d\n", k, i+j);
    }
    return 0;
}
