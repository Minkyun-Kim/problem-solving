/*
N Queen 문제. Backtracking을 이용해 푼다. 이전 문제는 정답이 되는 체스판 그림을 출력해야 했지만 이번엔 정답이 되는 경우를 카운팅만 하면 되기 때문에 pruning 한 경우 갯수만 올려준다. 
*/
class Solution {
    int sum = 0;
    int n;
    boolean[][] map;
    public int totalNQueens(int n) {
        this.map = new boolean[n][n];
        this.n = n;
        dfs(0);
        return sum;
    }
    
    public void dfs(int row){
        if(row == n){
            sum++;
            return;
        }
        for(int i = 0; i < n; i++){
            if(isPruning(row, i)){
                map[row][i] = true;
                dfs(row+1);
                map[row][i] = false;
            }
        }
    }
    
    public boolean isPruning(int r, int c){
        for(int i = 0; i < r; i++){
            if(map[r][i] == true)
                return false;
            if(map[i][c] == true)
                return false;
            int dist = r-i;
            if(c-dist >= 0 && map[r-dist][c-dist] == true){
                return false;
            }
            if(c+dist<n && map[r-dist][c+dist] == true){
                return false;
            }
        }
        return true;
    }

}
