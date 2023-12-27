#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int> &nums) {
        int n = nums.size();
        vector<int> idx_stack;
        vector<int> precost(n, 0), suffcost(n, 0);
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            auto it = lower_bound(idx_stack.begin(), idx_stack.end(), num);
            if (it == idx_stack.end()) {
                idx_stack.push_back(num);
            }
            else {
                idx_stack[it - idx_stack.begin()] = num;
            }
            precost[i] = (i + 1) - idx_stack.size();
            if (it - idx_stack.begin() == 0) {
                precost[i] = 0x3f3f3f3f;
            }
        }
        for (auto pre : precost) {
            cout << pre << " ";
        }
        cout << endl;
        vector<int>().swap(idx_stack);
        for (int i = n - 1; i >= 0; --i) {
            int num = nums[i];
            auto it = lower_bound(idx_stack.begin(), idx_stack.end(), num);
            if (it == idx_stack.end()) {
                idx_stack.push_back(num);
            }
            else {
                idx_stack[it - idx_stack.begin()] = num;
            }
            suffcost[i] = (n - i) - idx_stack.size();
            if (it - idx_stack.begin() == 0) {
                suffcost[i] = 0x3f3f3f3f;
            }
        }
        for (auto suff : suffcost) {
            cout << suff << " ";
        }
        cout << endl;
        int ans = 0x3f3f3f3f;
        for (int i = 1; i < n - 1; ++i) {
            ans = min(ans, precost[i] + suffcost[i]);
        }
        return ans;
    }
};

int main() {
    vector<int> v{ 1,3,1 };
    cout << Solution().minimumMountainRemovals(v);
    //system("pause");
    return 0;
}
