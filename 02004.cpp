#include <cstdio>
#include <algorithm>
int main(){
    long long n, m;
    scanf("%lld%lld", &n, &m);
    long long cnt2 = 0, cnt5 = 0;
    for(long long i = 2; i <= n ; i *= 2)
        cnt2 += n/i;
    for(long long i = 2; i <= m; i *= 2)
        cnt2 -= m/i;
    for(long long i = 2; i <= n-m; i *= 2)
        cnt2 -= (n-m)/i;
    for(long long i = 5; i<= n; i*= 5)
        cnt5 += n/i;
    for(long long i = 5; i <= m; i *= 5)
        cnt5 -= m/i;
    for(long long i = 5; i <= n-m; i *= 5)
        cnt5 -= (n-m)/i;
    printf("%lld\n",std::min(cnt2, cnt5));
    return 0;
}
