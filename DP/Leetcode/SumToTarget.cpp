#include <bits/stdc++.h>

using namespace std;

class Solution {
    const static int inf = 0x7f7f7f7f;
    int sumToTarget(vector<int> &nums, int target, function<int(int, int)> f) {
        int n = nums.size();
        vector<int> dp(target + 1, inf);
        dp[0] = 0;
        for (auto &num : nums) {
            for (int t = target; t >= num; --t) {
                dp[t] = f(dp[t], dp[t - num]);
            }
        }
        return dp[target] == inf ? -1 : dp[target];
    }
};

int main() {
    
    //system("pause");
    return 0;
}
