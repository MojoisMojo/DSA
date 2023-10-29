#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKOr(vector<int> &nums, int k) {
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            int cnt = 0;
            int mask = 1 << i;
            for (auto &num : nums) {
                cnt += (bool)(num & mask);
            }
            if (cnt >= k) {
                ans |= mask;
            }
        }
        return ans;
    }
};

int main() {

    //system("pause");
    return 0;
}
