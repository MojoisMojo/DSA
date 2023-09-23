#include <bits/stdc++.h>

using namespace std;
// dp解法
class Solution {
public:
    bool check(vector<int> nums,int k, int mx) {
        int interval = 0, neighbor = 0;
        for (int n : nums) {
            if (n > mx)
                interval = neighbor;
            else {
                int tmp = neighbor;
                neighbor = max(neighbor, interval + 1);
                interval = tmp;
            }
        }
        return neighbor >= k;
    }
    int minCapability(vector<int> &nums, int k) {
        int l = 0, r = *max_element(nums.begin(), nums.end());
        while (l + 1 < r) { // 开区间写法
            int mid = l + (r - l) / 2;
            (check(nums,k,mid) ? r : l) = mid;
        }
        return r;
    }
};
int main() {

    //system("pause");
    return 0;
}
