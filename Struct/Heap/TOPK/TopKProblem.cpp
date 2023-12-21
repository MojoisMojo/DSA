#include <bits/stdc++.h>

using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> topK;
    int k;
public:
    KthLargest(int k, vector<int> &nums):k(k) {
        for (auto num : nums) {
            topK.push(num);
        }
    }

    int add(int val) {
        if (val > topK.top()) {
            topK.push(val);
        }
        while (topK.size() > k) {
            topK.pop();
        }
        return topK.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */