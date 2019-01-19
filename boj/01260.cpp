#include <cstdio>
#include <queue>
using namespace std;
void dfs(int** a, int* check, int node, int n){
    check[node] = 1;
    printf("%d ", node);
    for(int i = 1;  i <= n; i++){
        if(a[node][i] == 1 && check[i] == 0)
            dfs(a, check, i, n);
    }
}

void bfs(int** a, int* check, int node, int n){
    queue<int> q;
    check[node] = 1;
    q.push(node);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        printf("%d ", x);
        for(int i = 1; i <= n; i++){
            if(a[x][i] == 1 && check[i] == 0){
                check[i] = 1;
                q.push(i);
            }
        }
    }
    printf("\n");
}

int main(){
    int n, v, start;
    scanf("%d %d %d", &n, &v, &start);
    int** a = new int*[n+1];
    int* check = new int[n+1]();
    for(int i = 0; i<= n; i++){
        a[i] = new int[n+1]();
    }
    for(int i = 0; i < v; i++){
        int from, to;
        scanf("%d %d",&from, &to);
        a[from][to] = a[to][from] = 1;
    }
    dfs(a, check, start, n);
    printf("\n");
    for(int i = 0; i <= n; i++)
        check[i] = 0;
    bfs(a, check, start, n);
    return 0;
}
