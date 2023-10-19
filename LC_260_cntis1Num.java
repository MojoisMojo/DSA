package JavaDSA;

public class LC_260_cntis1Num {

    class Solution {
        public int[] singleNumber(int[] nums) {
            int xo = 0;
            for (int num : nums) {
                xo ^= num;
            }
            int mask = (xo == Integer.MIN_VALUE ? xo : xo & (-xo));
            int[] ans = new int[2];
            ans[0]=0;
            ans[1]=0;
            for (int num : nums) {
                if ((num & mask) == 0) {
                    ans[0] ^= num;
                } else {
                    ans[1] ^= num;
                }
            }
            return ans;
        }
    }
}