#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int space = n-i, star = 2 * i - 1;
        while(space--)
            printf(" ");
        for(int j = 0 ; j < star; j++)
            printf("*");
        printf("\n");
    }
    n -= 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0 ; j < i; j++)
            printf(" ");
        int star = 2 *(n+1-i)  - 1;
        for(int j = 0; j < star ; j++)
            printf("*");
        printf("\n");
    }
    printf("\n");
    return 0;
}
