package JianZhiOffer47;

import java.util.Map;

/**
 * 动态规划
 */
public class Solution2 {
    private int maxValue;

    // 记忆化搜索
    private Map<int[], Integer> memory;

    public int maxValue(int[][] grid) {
        // 动态规划
        int[][] dp = new int[grid.length + 1][grid[0].length + 1];
        for (int i = 0; i <= grid.length; i++) {
            for (int j = 0; j <= grid[0].length; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (i > 0 && j > 0) {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
                }
            }
        }
        return dp[grid.length][grid[0].length];
    }
}
