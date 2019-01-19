#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        for(int j = 0; j <n-i; j++)
            printf(" ");
        printf("*");
        for(int j = 0; j < (i-1)*2 -1; j++)
            printf(" ");
        if(i>=2)
            printf("*");
        printf("\n");
    }
    for(int i = 0; i< 2*n-1; i++)
        printf("*");
    printf("\n");
}
