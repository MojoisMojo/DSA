#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> nextnextGreaterElement(vector<int> &nums) {
        // 2 0 3 1 4
        stack<int> sb;
        vector<int> ans(nums.size(), -1);
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            while (!sb.empty() && nums[sb.top()] < num) {
                ans[sb.top()] = i;
                sb.pop();
            }
            sb.push(i);
        }
        for (int i = 0; i < ans.size(); ++i) {
            if (ans[i] = -1) { continue; }
            else if (ans[ans[i]] = -1) { ans[i] = -1; }
            ans[i] = nums[ans[ans[i]]];
        }
        return ans;
    }
};

int main() {

    return 0;
}