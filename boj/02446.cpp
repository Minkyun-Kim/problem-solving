#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++)
            printf(" ");
        for(int j = 0; j < (n-i)*2+1; j++)
            printf("*");
        printf("\n");
    }

    n -= 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n-i ; j++)
            printf(" ");
        for(int j = 0; j < 2*i+1; j++)
            printf("*");
        printf("\n");
    }
    printf("\n");
    return 0;
}
