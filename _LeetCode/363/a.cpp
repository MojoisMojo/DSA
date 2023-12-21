#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size();i++) {
            int cnt = 0,num = nums[i];
            while (num > 0) {
                cnt+=num&1;
                num >>= 1;
            }
            if(cnt == k) ans += nums[i];
        }
        return ans;
    }
};
int main() {
    
    //system("pause");
    return 0;
}
