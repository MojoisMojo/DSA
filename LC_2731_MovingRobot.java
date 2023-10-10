package JavaDSA;

import java.util.Arrays;

public class LC_2731_MovingRobot {
    class Solution {
        static final int MOD = 1000000007;

        public int sumDistance(int[] nums, String s, int d) {
            int size = nums.length;
            long[] pos = new long[size];
            for (int i = 0; i < size; i++) {
                pos[i] = (long) nums[i] + (s.charAt(i) == 'R' ? d : -d);
            }
            Arrays.sort(pos);
            long res = 0;
            for (int i = 1; i < size; i++) {
                res += 1L * (pos[i] - pos[i - 1]) * i % MOD * (size - i) % MOD;
                res %= MOD;
            }
            return (int) res;
        }
    }
}
