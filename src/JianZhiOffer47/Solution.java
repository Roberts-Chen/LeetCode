package JianZhiOffer47;

/**
 * 记忆化搜索
 * 这其实是个万用的模板，对于那种棋盘上往四个方向走的也适用
 */
public class Solution {
    private int[][] dir = {{1, 0}, {0, 1}};
    private boolean[][] visited = new boolean[200][200];
    private int[][] memo = new int[200][200];
    public int maxValue(int[][] grid) {
        int maxCost = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (memo[i][j] != 0) {
                    maxCost = Math.max(maxCost, memo[i][j]);
                    continue;
                }
                visited[i][j] = true;
                maxCost = Math.max(maxCost, dfs(grid, i, j));
                visited[i][j] = false;
            }
        }
        return maxCost;
    }

    private int dfs(int[][] grid, int x, int y) {
        for (int i = 0; i < 2; i++) {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if (dx >= 0 && dx < grid.length && dy >= 0 && dy < grid[0].length && !visited[dx][dy]) {
                if (memo[dx][dy] != 0) {
                    memo[x][y] = Math.max(memo[x][y], memo[dx][dy]);
                    continue;
                }
                visited[dx][dy] = true;
                memo[x][y] = Math.max(memo[x][y], dfs(grid, dx, dy));
                visited[dx][dy] = false;
            }
        }
        memo[x][y] += grid[x][y];
        return memo[x][y];
    }
}
