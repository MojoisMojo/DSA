#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2;) {
            int a = nums[i];
            int j = i + 1, r = nums.size() - 1;
            while (j < r) {
                int b = nums[j], c = nums[r];
                int sum = a + b + c;
                if (sum > 0) { --r; }
                else if (sum < 0) { ++j; }
                else {
                    ans.push_back(vector<int>{a, b, c});
                    while (++j < r && nums[j] == b);
                    while (j < --r && nums[r] == c);
                }
            }
            while (++i < nums.size() && nums[i] == a);
        }
        return ans;
    }
};