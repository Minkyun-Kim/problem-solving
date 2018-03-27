/*
   처음에 2^n * 2^n 배열을 잡았지만 그럴 필요가 없었다. 값을 저장하지 않고 
   cnt값을 이용해 값만 구하면 된다.
   시간초과가 계속 났다.
   if 와 else에서 r < n 과 c < n으로 놨었다. n은 16->8->4->2->1 로 내려가므로 목적지와는 무관하다
   결국 시작주소 x, y에서 n만큼 이동한 값과 r,c를 비교하여야 한다.
 */
#include <iostream>
using namespace std;
int cnt, r, c;
int divide(int x, int y, int n) {
    if (r == x && c == y) {
        return cnt;
    }
    else {
        n /= 2;
        if (r < x + n) {//이 부분에서 r < n 으로 해서 시간초과남. 
            if (c <y + n)
                return divide(x, y, n);
            else {
                cnt += n * n;
                return divide(x, y + n, n);
            }
        }
        else {
            if (c < y + n) {
                cnt += n * n * 2;
                return divide(x + n, y, n);
            }
            else {
                cnt += n * n * 3;
                return divide(x + n, y + n, n);
            }
        }
    }
}

int main() {
    int n;
    cin >> n >> r >> c;
    cout << divide(0, 0, 1 << n) << '\n';
    return 0;
}
