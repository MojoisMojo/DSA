package JavaDSA;

import java.util.Arrays;

public class LC_16_3numsSum {
    // class Solution {
    // public int threeSumClosest(int[] nums, int target) {
    // int n = nums.length;
    // int[] dnums = new int[n];
    // for (int i = 0; i < n; i++) {
    // dnums[i] = nums[i] * 3 - target;
    // }
    // Arrays.sort(dnums);
    // int a = 0, b, c;
    // int ans = dnums[0] + dnums[1] + dnums[2];
    // while (ans != 0 && a < n - 2) {
    // b = a + 1;
    // c = n - 1;
    // while (ans != 0 && b + 1 < c) {
    // if (ans >= 0) {
    // int res = ans - dnums[(c--)];
    // res += dnums[c];
    // if (Math.abs(res) < Math.abs(ans)) {
    // ans = res;
    // }
    // } else {
    // int res = ans - dnums[(b++)];
    // res += dnums[b];
    // if (Math.abs(res) < Math.abs(ans)) {
    // ans = res;
    // }
    // }
    // }
    // a++;
    // }
    // return ans / 3 + target;

    // }
    // }
    class Solution {
        public int threeSumClosest(int[] nums, int target) {
            Arrays.sort(nums);
            int n = nums.length;
            int best = 10000000;

            // 枚举 a
            for (int i = 0; i < n; ++i) {
                // 保证和上一次枚举的元素不相等
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
                // 使用双指针枚举 b 和 c
                int j = i + 1, k = n - 1;
                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    // 如果和为 target 直接返回答案
                    if (sum == target) {
                        return target;
                    }
                    // 根据差值的绝对值来更新答案
                    if (Math.abs(sum - target) < Math.abs(best - target)) {
                        best = sum;
                    }
                    if (sum > target) {
                        // 如果和大于 target，移动 c 对应的指针
                        int k0 = k - 1;
                        // 移动到下一个不相等的元素
                        while (j < k0 && nums[k0] == nums[k]) {
                            --k0;
                        }
                        k = k0;
                    } else {
                        // 如果和小于 target，移动 b 对应的指针
                        int j0 = j + 1;
                        // 移动到下一个不相等的元素
                        while (j0 < k && nums[j0] == nums[j]) {
                            ++j0;
                        }
                        j = j0;
                    }
                }
            }
            return best;
        }
    }

}
