#include <cstdio>
int a[64][64];

bool find(int x, int y, int n){
    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++){
            if(a[x][y] != a[i][j])
                return false;
        }
    }
    return true;
}

void divide(int x, int y, int n){
    if(!find(x, y, n)){
        printf("(");
        divide(x, y, n/2);
        divide(x, y + n/2, n/2);
        divide(x + n/2, y, n/2);
        divide(x + n/2, y + n/2, n/2);
        printf(")");
    }
    else{
        printf("%d", a[x][y]);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    divide(0, 0, n);
    printf("\n");
    return 0;
}
