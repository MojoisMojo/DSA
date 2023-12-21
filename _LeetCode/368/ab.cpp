#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // [8,6,1,5,3]
    // [5,4,8,7,10,2]
    // [6,5,4,3,4,5]
    // [2,3,2,1]
    // [2,2,1]
    int minimumSum(vector<int> &nums) {
        int ans = 0x3f3f3f3f;
        int min_idxl = 0;
        int min_idxr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[min_idxl] > nums[i]) min_idxl = i;
            if (nums[min_idxr] >= nums[i]) min_idxr = i;
        }
        int min_num = nums[min_idxl];
        int ans1 = 0x3f3f3f3f, min1 = nums[0];
        for (int i = 1; i < min_idxr; i++) {
            if (nums[i] > min1)
                ans1 = min(nums[i] + min1, ans1);
            else if (nums[i] < min1) {
                min1 = nums[i];
            }
        }
        int ans2 = 0x3f3f3f3f, min2 = nums[nums.size()-1];
        for (int i = nums.size()-2; i > min_idxl ;i--) {
            if (nums[i] > min2)
                ans2 = min(nums[i] + min2, ans2);
            else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
        if (ans1 == 0x3f3f3f3f && ans2 == 0x3f3f3f3f) return -1;
        return min(ans1, ans2) + min_num;
    }
};

int main() {
    //system("pause");
    return 0;
}
