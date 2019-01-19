#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++)
            printf("*");
        
        for(int j = 0; j < 2*(n-i); j++)
            printf(" ");

        for(int j = 0; j < i; j++)
            printf("*");
        printf("\n");
    }
    n -= 1;
    for( int i = 0; i < n; i++){
        for(int j = 0; j < n-i ; j++)
           printf("*");
        
        for(int j = 0; j < (i+1)*2; j++)
            printf(" ");

        for(int j = 0; j < n-i; j++)
            printf("*");
        printf("\n");
    }
    printf("\n");
}
