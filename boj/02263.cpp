#include <iostream>
using namespace std;

int in[100000];
int post[100000];
int pos[100001];

void make(int in_start, int in_end, int post_start, int post_end){
    if(in_start > in_end || post_start > post_end)
        return;
    int root = post[post_end];
    int p = pos[root];
    cout << root << ' ';
    int num = p-in_start;
    make(in_start, p-1, post_start, post_start + num -1);
    make(p+1, in_end, post_start + num, post_end-1);//포스트오더의 시작점을 기존 시작점에서 왼쪽갯수만큼 올려서 잡는다.
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> in[i];
    for(int i = 0; i < n; i++)
        pos[in[i]] = i;//인오더 숫자의 위치를 기억해두고 포스트오더에서 루트를 찾아 인오더에서 해당 숫자를 찾을때  빠르게 찾아
    for(int i = 0; i < n; i++)
        cin >> post[i];
    make(0, n-1, 0, n-1);
    cout << '\n';
    return 0;
    
}
