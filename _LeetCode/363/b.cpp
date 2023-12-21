#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const auto &a, const auto &b)->auto {return a < b;});
        // 0,2,3,3,6,6,7,7
        // 1,2,3,4,5,6,7,8,
        // nums[idx] < idx + 1 < nums[idx + 1]
        int ans = (nums[0] != 0), N = nums.size();
        for (int i = 0; i < N - 1;i++) {
            if (nums[i] < i + 1 && i + 1 < nums[i + 1]) ans += 1;
        }
        return nums[N - 1] < N ? ans + 1 :ans;
    }
};
int main() {
    
    //system("pause");
    return 0;
}
