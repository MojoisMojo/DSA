#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minIncrementOperations(vector<int> &nums, int k) {
        //dp[i][0] = dp[i-1][1] dp[i-2][1]
        //dp[i][1] = min(dp[i-1]) min(dp[i-2]) (dp[i-3][1] + daijia)
        if (nums.size() < 3) {
            int maxi = -1;
            for (auto &num : nums) {
                maxi = max(maxi, num);
            }
            return max(0, k - maxi);
        }
        // size >= 3
        int len = nums.size();
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = max(0, k - nums[0]);
        dp[1][0] = dp[0][1];
        dp[1][1] = max(0, k - nums[1]);
        dp[2][0] = min(dp[0][1], dp[1][1]);
        dp[2][1] = max(0, k - nums[2]);
        for (int i = 3; i < nums.size(); i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 2][1]);
            dp[i][1] = dp[i - 3][1] + max(0, k - nums[i]);
        }
        for (auto v : dp) {
            cout << "[" << v[0] << " " << v[1] << "], ";
        }
        return min(dp[len - 1][0], dp[len - 1][1]);
    }
};

int main() {
    vector<int> n{ 4,0,10,2,10,6 };
    // dp[i][0] = 
    // dp[i][1] = dp[i-3][0] + cost
    int k = 8;
    cout << endl << Solution().minIncrementOperations(n,k);
    //system("pause");
    return 0;
}
