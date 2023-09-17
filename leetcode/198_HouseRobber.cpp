#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp{{0,0}};
        for (int &num : nums) {
            int t = dp[1];
            dp[1] = dp[0] > dp[1] ? dp[0] : dp[1];
            dp[0] = t + num;
        }
        return dp[0] > dp[1] ? dp[0] : dp[1];
    }
};
int main() {
    
    //system("pause");
    return 0;
}
