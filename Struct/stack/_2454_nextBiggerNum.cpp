#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> secondGreaterElement(vector<int> &nums) {
        // 2 0 3 1 4
        stack<int> sa, sb;
        vector<int> ans(nums.size(), -1);
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            while (!sb.empty() && nums[sb.top()] < num) {
                ans[sb.top()] = num;
                sb.pop();
            }
            stack<int> t;
            while (!sa.empty() && nums[sa.top()] < num) {
                t.push(sa.top());
                sa.pop();
            }
            while (!t.empty()) {
                sb.push(t.top());
                t.pop();
            }
            sa.push(i);
        }
        return ans;
    }
};

int main() {

    return 0;
}