#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int height, width;
    cin >> height >> width;
    if (height == 1)//이동시 위아래로 움직여야 하므로 이동할 수 있는 공간이 없다.
        cout << 0 << '\n';
    else if (height == 2)//네 가지중 두 가지를 이용해 움직일수 밖에 없기 때문에 4보다 클 수 없다
        cout << min(4, (width +1)/2) << '\n';//두 칸마다 움직일 수 있으므로 (width+1)/2
    else if(height >= 3){//네 가지를 모두 이용할 수 있다.
        if( width < 7)//네 가지를 모두 이용할 경우 7칸 이상이 필요하기 때문에 7보다 작은 너비에서
            cout << min(4, width) << '\n';//최대로 이동하려면 위로 두칸, 오른쪽 한 칸 이동이 최대다.
        else    //7칸 이상이면 네 가지를 모두 사용할 수 있다. 최대가 되게 하기 위해서 오른쪽으로 길게 이동하는
            cout << width - 2 << '\n';//경우는 최소한으로 이동하고(위1우2, 아래1우2) 위2우1 또는 아래2우1을 이용한다.
    }
    return 0;
}
