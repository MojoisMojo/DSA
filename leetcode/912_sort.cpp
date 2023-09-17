#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> temp;
    void merge_sort(vector<int> &nums, int l, int r) {
        if (l > r) return;
        int mid = l + (r - l) >> 1, idx = 0, i = l, j = mid + 1;
        merge_sort(nums, l, mid);   merge_sort(nums, mid+1, r);
        while (i <= mid && j <= r) temp[idx++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
        while (i <= mid) temp[idx++] = nums[i++];
        while (j <= r) temp[idx++] = nums[j++];
        while (idx--) nums[l + idx] = temp[idx];
    }
public:
    vector<int> sortArray(vector<int> &nums) {
        int len = nums.size();
        temp.resize(len);
        merge_sort(nums, 0, len - 1);
        return nums;
    }
};

int main() {
    vector<int> a{ {3,5,2,8} };
    for_each(a.begin(), a.end(), [](const auto &i) {cout << i << " ";});
    a = Solution().sortArray(a);
    for_each(a.begin(), a.end(), [](const auto &i) {cout << i << " ";});
    //system("pause");
    return 0;
}
