package JavaDSA.LC_366;

public class LC_2906_MarixMultiply {
    class Solution {
        public int[][] constructProductMatrix(int[][] grid) {
            final int MOD = 12345;
            int colLength = grid.length, rowLength = grid[0].length;
            int[][] ans = new int[colLength][rowLength];
            long pre = 1;
            for (int i = 0; i < colLength; i++) {
                for (int j = 0; j < rowLength; j++) {
                    ans[i][j] = (int) pre;
                    pre = (pre * grid[i][j]) % MOD;
                }
            }
            long suf = 1;
            for (int i = colLength - 1; i >= 0; --i) {
                for (int j = rowLength - 1; j >= 0; --j) {
                    ans[i][j] = (int) ((long) ans[i][j] * suf) % MOD;
                    suf = (suf * grid[i][j]) % MOD;
                }
            }

            return ans;
        }
    }
}
