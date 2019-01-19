#include <cstdio>

int main(){
    int n, temp;
    scanf("%d", &n);
    temp = n;
    for(int i = 2; i*i <= temp; i++){
        while(n%i == 0){
            printf("%d\n", i);
            n /=i;
        }
    }
    if( n > 1)
        printf("%d\n", n);
    return 0;
}
