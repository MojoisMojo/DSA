#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        priority_queue<pair<int, int>>pq;
        vector<int> ans(nums.size() - k + 1);
        for (int i = 0; i < k; ++i) {
            pq.push({ nums[i], i });
        }
        ans[0] = pq.top().first;
        for (int i = k; i < nums.size(); ++i) {
            pq.push({ nums[i], i });
            while(pq.top().second <= i - k) {
                pq.pop();
            }
            ans[i - k + 1] = pq.top().first;
        }
        return ans;
    }
};

int main() {

    //system("pause");
    return 0;
}
