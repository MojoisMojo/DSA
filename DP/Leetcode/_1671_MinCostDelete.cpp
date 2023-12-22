#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int> &nums) {
        // 1 4 5 2 6 7 6
        // 4 1 2 3
        // idx
        // find < num 最大
        // stack:[i,j], precost[j] = precost[i] + (j-i-1)
        int n = nums.size();
        vector<int> idx_stack;
        vector<int> precost(n, 0), suffcost(n, 0);
        for (int i = 0; i < n; ++i) {
            idx_stack.insert(lower_bound(idx_stack.begin(), idx_stack.end(), i, [&](int x, int y)->bool {return nums[x] < nums[y];}), i);
            int j = idx_stack.top();
            suffcost[i] = suffcost[j] + j - i - 1;
            idx_stack.push(i);`
        }
        for (auto pre : precost) {
            cout << pre << " ";
        }
        cout << endl;
        for (int i = n - 1; i >= 0; --i) {
            while (!idx_stack.empty() && nums[idx_stack.top()] >= nums[i]) {
                idx_stack.pop();
            }
            if (idx_stack.empty()) {
                suffcost[i] = n - i - 1;
            }
            else {
                int j = idx_stack.top();
                suffcost[i] = suffcost[j] + j - i - 1;
            }
            idx_stack.push(i);
        }
        for (auto suff : suffcost) {
            cout << suff << " ";
        }
        cout << endl;
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, precost[i] + suffcost[i]);
        }
        return ans;
    }
};

int main() {


    //system("pause");
    return 0;
}
