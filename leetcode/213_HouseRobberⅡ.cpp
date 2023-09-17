#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob1(vector<int> &nums,int begin,int end){//空间优化版
        int n = nums.size();
        int f0 = 0, f1 = 0;
        for(int i = begin;i <= end;++i){
            int ans = max(f0 + nums[i], f1);
            f0 = f1;
            f1 = ans;
        }
        return f1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];//注意下标
        return max(rob1(nums, 0, n - 2), rob1(nums, 1, n - 1));
    }
};

int main() {
    vector<int> v{ 1,2,3 };
    cout << *(max_element(v.begin(), v.end()));
    //system("pause");
    return 0;
}
