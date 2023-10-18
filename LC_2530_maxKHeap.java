package JavaDSA;

import java.util.PriorityQueue;

public class LC_2530_maxKHeap {
    class Solution {
        public long maxKelements(int[] nums, int k) {
            PriorityQueue<Integer> q = new PriorityQueue<Integer>((a, b) -> b - a);
            for (int num : nums) {
                q.offer(num);
            }
            long ans = 0;
            for (int i = 0; i < k; ++i) {
                int x = q.poll();
                ans += x;
                q.offer((x + 2) / 3);
            }
            return ans;
        }
    }
}
