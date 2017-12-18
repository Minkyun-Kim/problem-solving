#include <stdio.h>

int main()
{
    char a[111];
    while (scanf("%[^\n]\n",a)==1){
        printf("%s\n", a);
    }
    return 0;
}
