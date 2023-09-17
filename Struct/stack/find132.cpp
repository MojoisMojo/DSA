#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool find132pattern(vector<int> &nums) {
        stack<int> st;
        int n = nums.size(), k = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < k) return true;
            while (!st.empty() and st.top() < nums[i])
            {
                k = max(k, st.top());
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
int main() {

    //system("pause");
    return 0;
}
