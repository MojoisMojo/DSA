#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        //贪心
        long long dp2 = 0, dp1 = 0, dp0 = 0;
        for (auto &n : nums) {
            long long t = dp2 + max(n - k, 0);
            dp2 = min(t, dp1);
            dp1 = min(t, dp0);
            dp0 = t;
        }
        return dp2;
    }
};

int main() {
    
    //system("pause");
    return 0;
}
