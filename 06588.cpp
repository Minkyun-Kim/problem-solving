#include <cstdio>
using namespace std;
bool a[1000001];
int pn;
int pri[1000001];

int main(){
    int n;
    for(int i = 2; i*i <= 1000000; i++){
        if(a[i] == 0){
            pri[pn++] = i;
            for(int j = i*i; j <= 1000000; j+=i){
                a[j] = 1;
            }
        }
    }

    while(true){
        scanf("%d", &n);
        if( n == 0 )
            break;
        for(int i = 1; i < pn; i++){
                if(a[n-pri[i]] == 0){
                    printf("%d = %d + %d\n", n, pri[i], n-pri[i]);
                    //cout << n << " = " << pri[i] << " + " << n-pri[i] << '\n';
                    break;
                }
        }
    }
    return 0;
}
