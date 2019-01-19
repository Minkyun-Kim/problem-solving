#include <iostream>
#include <queue>
using namespace std;
int br[100001];
bool check[100001];

int main(){
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    queue<int> q;
    q.push(n);
    check[n] = true;
    while(!q.empty()){
        int pos = q.front();
        q.pop();
        if(pos == m){
            cout << br[pos] << '\n';
            break;
        }
        int move[] = {-1, 1, -a, -b, a, b, pos*a, pos*b};
        for(int i = 0; i < 8; i++){
            int npos;
            if(i >= 0 && i <= 5)
                npos = pos + move[i];
            else
                npos = move[i];
            if(npos >= 0 && npos <= 100000 && !check[npos]){
                check[npos] = 1;
                q.push(npos);
                br[npos] = br[pos]+1;
                
            }
        }
    }
    return 0;
}
