#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", (n - n%5)/5 + (n - n%25)/25 + (n - n%125)/125);
    return 0;
}
