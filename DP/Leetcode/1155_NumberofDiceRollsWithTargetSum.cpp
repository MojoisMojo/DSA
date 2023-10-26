#include <bits/stdc++.h>

using namespace std;

// const int MOD = 1000000007;
// class Solution {
// public:
//     int numRollsToTarget(int n, int k, int target) {
//         if (n < 0 || target < 0 || k <= 0 || n > target || n * k < target) return 0;
//         if (target == n) return 1;
//         // else
//         if (k == 1) return 0;
//         return helper2(n, k, target);
//     }

//     int helper1(int n, int k, int target) {
//         if (n < 0 || target < 0 || n > target) return 0;
//         if (target == n) return 1;
//         int sum = 0;
//         for (int dice = 1; dice <= k; ++dice) {
//             sum = (sum + helper1(n - 1, k, target - dice)) % MOD;
//         }
//         return sum;
//     }

//     int helper2(int n, int k, int target) {
//         int dp[target + 1];
//         memset(dp, 0, sizeof(dp));
//         for (int i = 0; i <= n; ++i) {
//             for (int t = min(k * i, target); t > i; --t) {
//                 dp[t] = 0;
//                 for (int dice = 1; dice <= k; ++dice) {
//                     if (t - dice < 0) break;
//                     dp[t] = (dp[t] + dp[t - dice]) % MOD;
//                 }
//             }
//             dp[i] = 1;
//             if (i) dp[i - 1] = 0;
//         }
//         return dp[target];
//     }
// };
const int MOD = 1000000007;
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if (n < 0 || target < 0 || k <= 0 || n > target || n * k < target) return 0;
        if (target == n) return 1;
        if (k == 1) return 0;
        int dp[target + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; ++i) {
            for (int t = min(k * i, target); t > i; --t) {
                dp[t] = 0;
                for (int dice = 1; dice <= k; ++dice) {
                    if (t - dice < 0) break;
                    dp[t] = (dp[t] + dp[t - dice]) % MOD;
                }
            }
            dp[i] = 1;
            if (i) dp[i - 1] = 0;
        }
        return dp[target];
    }
};



int main() {
    int n, k, t;
    cin >> n >> k >> t;
    Solution().numRollsToTarget(n, k, t);
    //system("pause");
    return 0;
}