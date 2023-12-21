#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int> &nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int cnt_mx = 0, left = 0;
        for (int x : nums) {
            cnt_mx += x == mx;
            while (cnt_mx == k) {
                cnt_mx -= nums[left++] == mx;
            }
            ans += left;
        }
        return ans;
    }
};


int main() {

    //system("pause");
    return 0;
}
