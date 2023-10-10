package JavaDSA;

import java.util.Arrays;

public class LC_16_3numsSum {
    class Solution {
        public int threeSumClosest(int[] nums, int target) {
            int n = nums.length;
            int[] dnums = new int[n];
            for (int i = 0; i < n; i++) {
                dnums[i] = nums[i] * 3 - target;
            }
            Arrays.sort(dnums, ((x, y) -> Integer.compare(x, y)));
            
        }
    }
}
