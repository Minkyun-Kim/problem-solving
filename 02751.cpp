#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int a[1000000];
    for(int i = 0; i< n; i++){
        scanf("%d", &a[i]);
    }
    /*
    for(int i = 0; i< n-1; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }*/
    sort(a, a+n);
    for(int i = 0; i < n; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}
