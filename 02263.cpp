#include <iostream>
using namespace std;

int in[100000];
int post[100000];
int a[100001][2];

void make(int in_start, int in_end, int post_start, int post_end){
    cout << post[post_end] << ' ';
    if(in_start >= in_end || post_start >= post_end)
        return;
    int i;
    for(i = in_start; i <= in_end; i++)
        if(in[i] == post[post_end])
            break;
    make(in_start, i-1, post_start, i-1);
    make(i+1, in_end, i, post_end-1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> in[i];
    for(int i = 0; i < n; i++)
        cin >> post[i];
    make(0, n-1, 0, n-1);
    cout << '\n';
    return 0;
    
}
