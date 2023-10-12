package JavaDSA;

public class LC_741_grab_Berry {
    class Solution {
        public int cherryPickup(int[][] grid) {
            if (grid[0][0] == -1)
                return 0;
            int[] dp = new int[grid.length];
            dp[0] = grid[0][0];
            for (int j = 1; j < grid.length; j++) {
                if (grid[0][j] == -1 || dp[j - 1] == -1) {
                    dp[j] = -1;
                } else {
                    dp[j] = dp[j - 1] + grid[0][j];
                }
            }
            for (int i = 1; i < grid.length; i++) {
                if (dp[0] != -1 && grid[i][0] != -1) {
                    dp[0] += grid[i][0];
                } else {
                    dp[0] = -1;
                }
                for (int j = 1; j < grid.length; j++) {
                    if (grid[i][j] == -1 || (dp[j] == -1 && dp[j - 1] == -1)) {
                        dp[j] = -1;
                    } else if (dp[j] == -1) {
                        dp[j] = dp[j - 1] + grid[i][j];
                    } else if (dp[j - 1] == -1) {
                        dp[j] += grid[i][j];
                    } else {
                        dp[j] = Math.max(dp[j], dp[j - 1]);
                    }
                }
            }
            return dp[grid.length - 1] == -1 ? 0 : dp[grid.length - 1];
        }
        
    }
}
