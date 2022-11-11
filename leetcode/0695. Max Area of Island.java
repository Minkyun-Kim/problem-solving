/**
 * DFS, BFS 기본 문제
 * 1이 체크된 지점에서 상, 하, 좌, 우 네 방향으로 dfs 탐색을 하고 다녀간 만큼의 넓이를 구해주면 된다.
 */
class Solution {
    int[][] directions={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m;
    int n;
    public int maxAreaOfIsland(int[][] grid) {
        this.m = grid.length;
        this.n = grid[0].length;
        
        int max = 0;
        for(int i = 0; i < grid.length; i++){
            for(int j = 0;j < grid[i].length; j++){    
                max = Math.max(dfs(grid, i, j, 0), max);
            }
        }
        return max;
    }
    
    public int dfs(int[][] grid, int r, int c, int div){
        if(grid[r][c] == 0)
            return div;
        grid[r][c] = 0;
        for(int i = 0; i < 4; i++){
            int nx = r+directions[i][0];
            int ny = c+directions[i][1];
            if(nx >= 0 && nx <m && ny >= 0 && ny < n){
                div = dfs(grid, nx, ny, div);
            }
        }
        return div+1;
        
    }
}
